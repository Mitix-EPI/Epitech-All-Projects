import discord
import os
from dotenv import load_dotenv
from discord.ext import tasks 
from discord.ext import commands


class DisBot(commands.Bot) :
    def __init__(self) :
        commands.Bot.__init__(self, command_prefix="")
        load_dotenv()
        self.token = os.getenv('DISCORD_TOKEN')
        self.client = discord.Client()
        self.react = False
        self.user_id = 0
        self.message = ""

    async def run(self) :
        await self.client.start(self.token)

    @tasks.loop(seconds=1)
    async def mytask(self) :
        if self.react == True :
            user = await self.client.fetch_user(user_id=self.user_id)
            self.react = False
            print(f'Sending message "{self.message}" to {user}', flush=True)
            await user.send(self.message)

    def send_message(self, user_id, message) -> bool :
        self.user_id = user_id
        self.message = message
        self.react = True
        print(f'Sending message to {user_id}', flush=True)
        return True

# bot = DisBot()

# @bot.client.event
# async def on_ready():
#     bot.mytask.start()