import os
from uuid import uuid4
from datetime import datetime
import urllib.parse
import requests

state_list = []

class RedditActions():
    def __init__(self) -> None:
        self.base_link = "https://oauth.reddit.com/"
        self.redirect_uri = "http://localhost:8081/auth/reddit"
        self.token_json = None

    def oauth_link_generation(self) -> str:
        state = uuid4()
        state_list.append({"state": state, "created": datetime.now()})
        base_url = "https://ssl.reddit.com/api/v1/authorize?"
        params = {
            "client_id": os.getenv("REDDIT_CLIENT"),
            "response_type": "code",
            "state": state,
            "redirect_uri": self.redirect_uri,
            "duration": "permanent",
            "scope": "identity account read mysubreddits",
        }
        url = base_url + urllib.parse.urlencode(params)
        return url

    def get_tokens(self, code: str):
        # print(state_list)
        # if state not in state_list:
        #     return False
        # del state_list[state_list.index(state)]
        client_auth = requests.auth.HTTPBasicAuth(os.getenv("REDDIT_CLIENT"), os.getenv("REDDIT_API"))
        post_data = {"grant_type": "authorization_code", "code": code, "redirect_uri": self.redirect_uri}
        headers = {"User-agent": "python:dashboard (/u/MrUrica)"}

        response = requests.post("https://ssl.reddit.com/api/v1/access_token", headers=headers, auth=client_auth, data=post_data)
        self.token_json = response.json()
        # print(self.token_json)
        # print(self.get_profile("843324911692-Ir-pkB9lImbKdETWwU1qLyRkKgXYWg"))
        return self.token_json

    #################################################################################################
    #                                            ACTIONS                                            #
    #################################################################################################

    def check_subscribers(self, token: str, user: str, value: int, operand: str) -> bool:
        headers = {"Authorization": "bearer " + token, "User-agent": "python:dashboard (/u/MrUrica)"}
        response = requests.get("https://oauth.reddit.com/user/" + user + "/about", headers=headers)
        json_response = response.json()
        subscribers = int(json_response["data"]["subreddit"]["subscribers"])

        if operand == ">":
            return subscribers > value
        elif operand == "<":
            return subscribers < value
        elif operand == "<=":
            return subscribers <= value
        elif operand == ">=":
            return subscribers >= value
        elif operand == "=":
            return subscribers == value
        return False

    def check_coins(self, token: str, value: int, operand: str) -> bool:
        headers = {"Authorization": "bearer " + token, "User-agent": "python:dashboard (/u/MrUrica)"}
        response = requests.get("https://oauth.reddit.com/api/v1/me", headers=headers)
        json_response = response.json()
        coins = int(json_response["coins"])

        if operand == ">":
            return coins > value
        elif operand == "<":
            return coins < value
        elif operand == "<=":
            return coins <= value
        elif operand == ">=":
            return coins >= value
        elif operand == "=":
            return coins == value
        return False

    def check_karma(self, token: str, user: str, value: int, operand: str) -> bool:
        headers = {"Authorization": "bearer " + token, "User-agent": "python:dashboard (/u/MrUrica)"}
        response = requests.get("https://oauth.reddit.com/user/" + user + "/about", headers=headers)
        json_response = response.json()
        karma = int(json_response["data"]["total_karma"])

        if operand == ">":
            return karma > value
        elif operand == "<":
            return karma < value
        elif operand == "<=":
            return karma <= value
        elif operand == ">=":
            return karma >= value
        elif operand == "=":
            return karma == value
        return False, None

    def get_last_new_subreddit_name(self, token: str, value: str, operand: str) -> bool:
        headers = {"Authorization": "bearer " + token, "User-agent": "python:dashboard (/u/MrUrica)"}
        response = requests.get("https://oauth.reddit.com/subreddits/new?limit=1", headers=headers)
        json_response = response.json()
        name: str = json_response["data"]["children"][0]["data"]["display_name"]

        if operand == "start with":
            return name.startswith(value)
        elif operand == "not start with":
            return not name.startswith(value)
        elif operand == "end with":
            return name.endswith(value)
        elif operand == "not end with":
            return name.endswith(value)
        return False

    def get_last_popular_subreddit_name(self, token: str, value: str, operand: str) -> bool:
        headers = {"Authorization": "bearer " + token, "User-agent": "python:dashboard (/u/MrUrica)"}
        response = requests.get("https://oauth.reddit.com/subreddits/popular?limit=1", headers=headers)
        json_response = response.json()
        name: str = json_response["data"]["children"][0]["data"]["display_name"]

        if operand == "start with":
            return name.startswith(value)
        elif operand == "not start with":
            return not name.startswith(value)
        elif operand == "end with":
            return name.endswith(value)
        elif operand == "not end with":
            return name.endswith(value)
        return False

    def get_last_gold_subreddit_name(self, token: str, value: str, operand: str) -> bool:
        headers = {"Authorization": "bearer " + token, "User-agent": "python:dashboard (/u/MrUrica)"}
        response = requests.get("https://oauth.reddit.com/subreddits/gold?limit=1", headers=headers)
        json_response = response.json()
        name: str = json_response["data"]["children"][0]["data"]["display_name"]

        if operand == "start with":
            return name.startswith(value)
        elif operand == "not start with":
            return not name.startswith(value)
        elif operand == "end with":
            return name.endswith(value)
        elif operand == "not end with":
            return name.endswith(value)
        return False

    def get_last_default_subreddit_name(self, token: str, value: str, operand: str) -> bool:
        headers = {"Authorization": "bearer " + token, "User-agent": "python:dashboard (/u/MrUrica)"}
        response = requests.get("https://oauth.reddit.com/subreddits/default?limit=1", headers=headers)
        json_response = response.json()
        name: str = json_response["data"]["children"][0]["data"]["display_name"]

        if operand == "start with":
            return name.startswith(value)
        elif operand == "not start with":
            return not name.startswith(value)
        elif operand == "end with":
            return name.endswith(value)
        elif operand == "not end with":
            return name.endswith(value)
        return False

    def get_first_new_by_subreddit_name(self, token: str, subreddit: str, value: str, operand: str) -> bool:
        headers = {"Authorization": "bearer " + token, "User-agent": "python:dashboard (/u/MrUrica)"}
        response = requests.get("https://oauth.reddit.com/r/" + subreddit + "/new?limit=1", headers=headers)
        json_response = response.json()
        name: str = json_response["data"]["children"][0]["data"]["title"]

        if operand == "start with":
            return name.startswith(value)
        elif operand == "not start with":
            return not name.startswith(value)
        elif operand == "end with":
            return name.endswith(value)
        elif operand == "not end with":
            return name.endswith(value)
        return False

    def get_first_hot_by_subreddit_name(self, token: str, subreddit: str, value: str, operand: str) -> bool:
        headers = {"Authorization": "bearer " + token, "User-agent": "python:dashboard (/u/MrUrica)"}
        response = requests.get("https://oauth.reddit.com/r/" + subreddit + "/hot?limit=1", headers=headers)
        json_response = response.json()
        name: str = json_response["data"]["children"][0]["data"]["title"]

        if operand == "start with":
            return name.startswith(value)
        elif operand == "not start with":
            return not name.startswith(value)
        elif operand == "end with":
            return name.endswith(value)
        elif operand == "not end with":
            return name.endswith(value)
        return False

    def get_first_top_by_subreddit_name(self, token: str, subreddit: str, value: str, operand: str) -> bool:
        headers = {"Authorization": "bearer " + token, "User-agent": "python:dashboard (/u/MrUrica)"}
        response = requests.get("https://oauth.reddit.com/r/" + subreddit + "/top?limit=1", headers=headers)
        json_response = response.json()
        name: str = json_response["data"]["children"][0]["data"]["title"]

        if operand == "start with":
            return name.startswith(value)
        elif operand == "not start with":
            return not name.startswith(value)
        elif operand == "end with":
            return name.endswith(value)
        elif operand == "not end with":
            return name.endswith(value)
        return False

    # def get_profile(self, token):
    #     # self.token_json["access_token"]
    #     headers = {"Authorization": "bearer " + token, "User-agent": "python:dashboard (/u/MrUrica)"}
    #     response = requests.get("https://oauth.reddit.com/api/v1/me", headers=headers)
    #     json_response = response.json()
    #     result = {"subscribers": json_response["subreddit"]["subscribers"], "coins": json_response["coins"], "karma": json_response["total_karma"]}

    #     return result
