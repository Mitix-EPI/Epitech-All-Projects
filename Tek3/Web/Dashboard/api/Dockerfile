FROM python:3.8

ENV GOOGLE_CLIENT_ID 1067891263194-g7mhnv07l29qh7315njp6m4vvljuvrvj.apps.googleusercontent.com
ENV GOOGLE_CLIENT_SECRET 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

WORKDIR app

COPY * /app/

EXPOSE 8089

RUN pip install -r requirements.txt

CMD ["python", "app.py"]