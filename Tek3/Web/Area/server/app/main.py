import threading
import time
from typing import Optional
import uvicorn
import app.routes.auth as auth
import app.routes.about as about
import app.routes.actions as actions
import app.routes.subscribe as subscribe
import app.routes.spotify as spotify
import app.routes.reddit as reddit
import app.worker.worker as worker
import app.routes.token as token
from dotenv import load_dotenv

from fastapi import FastAPI

from fastapi.middleware.cors import CORSMiddleware

import asyncio

load_dotenv()
isDoneOnce = False
app = FastAPI()

origins = [
    "http://localhost",
    "http://localhost:8080",
    "http://localhost:8081",
    "http://localhost:8100",
    "http://127.0.0.1",
    "http://127.0.0.1:8080",
    "http://127.0.0.1:8081",
    "http://127.0.0.1:8100",
]

app.add_middleware(
    CORSMiddleware,
    allow_origins=origins,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)
app.include_router(auth.router)
app.include_router(about.router)
app.include_router(actions.router)
app.include_router(subscribe.router)
app.include_router(token.router)
app.include_router(reddit.router)
app.include_router(spotify.router)

@app.get("/")
def read_root():
    return {"Hello": "My World"}

@app.get("/items/{item_id}")
def read_item(item_id: int, q: Optional[str] = None):
    return {"item_id": item_id, "q": q}

my_worker = worker.Worker()
def start_worker():
    print('[main]: starting worker...', flush=True)
    my_worker.working_loop()

@my_worker.__discord__.client.event
async def on_ready():
    print('[main]: disbot is ready', flush=True)
    my_worker.__discord__.mytask.start()


@app.on_event("startup")
async def startup_event():
    global isDoneOnce
    if (isDoneOnce == False):
        print('[main]: starting background tasks...', flush=True)
        t = threading.Thread(target=start_worker, daemon=True)
        t.start()
        asyncio.ensure_future(my_worker.__discord__.run())
        print('[main]: background tasks started', flush=True)
    isDoneOnce = True

if __name__ == '__main__':
    print('[main]: starting...', flush=True)
    uvicorn.run(app, host="0.0.0.0", port=8000, reload=True)