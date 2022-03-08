from fastapi import APIRouter, Request
import time

from pydantic import BaseModel
from app.services.farmersworld.farmersworld import FarmersWorldActions

router = APIRouter()

class Test(BaseModel):
    operand: str
    value: float

@router.post("/test")
async def test(request: Test):
    fwa = FarmersWorldActions()
    operand = request.operand
    value = request.value

    print(f'operand: "{operand}" value: "{value}"')

    res_basic = await fwa.fww_price_action(operand, value)
    res_refresh = await fwa.fww_price_action_refresh(operand, value)

    return { "fww_price_action": res_basic, "fww_price_action_refresh": res_refresh }

@router.get("/about.json")
def about(request: Request):
    host = request.client.host
    currentTime = int(time.time())

    return {
        "client": {
            "host": host,
        },
        "server": {
            "time": currentTime,
            "services": [
                {
                    "display_name": "Farmers World",
                    "name": "farmersworld",
                    "icon": "https://farmersworld.io/favicon.ico",
                    "authentication_required": None,
                    "actions": [
                        {
                            "display_name": "FWW Price",
                            "name": "fww_price_check",
                            "description": "Check if the FWW price is >, <, =, >=, <= a value",
                            "arguments": [
                                {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "Value",
                                    "name": "value",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "fww_price_check",
                                "operand": None,
                                "value": None,
                            }
                        }, {
                            "display_name": "FWF Price",
                            "name": "fwf_price_check",
                            "description": "Check if the FWF price is >, <, =, >=, <= a value",
                            "arguments": [
                                {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "Value",
                                    "name": "value",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "fwf_price_check",
                                "operand": None,
                                "value": None,
                            }
                        }, {
                            "display_name": "FWG Price",
                            "name": "fwg_price_check",
                            "description": "Check if the FWG price is >, <, =, >=, <= a value",
                            "arguments": [
                                {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "Value",
                                    "name": "value",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "fwg_price_check",
                                "operand": None,
                                "value": None,
                            }
                        }, {
                            "display_name": "WAX Price",
                            "name": "wax_price_check",
                            "description": "Check if the WAX price is >, <, =, >=, <= a value",
                            "arguments": [
                                {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "Value",
                                    "name": "value",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "wax_price_check",
                                "operand": None,
                                "value": None,
                            }
                        }, {
                            "display_name": "FarmersWorld fees",
                            "name": "fees_check",
                            "description": "Check if the FarmersWorld fees are >, <, =, >=, <= a value",
                            "arguments": [
                                {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "Value",
                                    "name": "value",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "fees_price_check",
                                "operand": None,
                                "value": None,
                            }
                        }
                    ],
                    "reactions": [],
                }, {
                    "display_name": "League of Legends",
                    "name": "leagueoflegends",
                    "icon": "https://vortexcgo.com/wp-content/uploads/2021/10/b83e6fea403a390bd06ae17c187408e3.png",
                    "authentication_required": None,
                    "actions": [
                        {
                            "display_name": "League of Legends Summoner Level",
                            "name": "summoner_level_check",
                            "description": "Check if the summoner level is >, <, =, >=, <= a value",
                            "arguments": [
                                {
                                    "display_name": "Region",
                                    "name": "region",
                                    "type": "string",
                                    "default": "euw1",
                                    "options": [
                                        {
                                            "name": "euw1",
                                        },
                                        {
                                            "name": "na1",
                                        },
                                        {
                                            "name": "eun1",
                                        },
                                        {
                                            "name": "kr",
                                        }
                                    ],
                                }, {
                                    "display_name": "Summoner Name",
                                    "name": "summoner_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "level",
                                    "name": "level",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "summoner_level_check",
                                "region": None,
                                "summoner_name": None,
                                "operand": None,
                                "level": None,
                            }
                        }, {
                            "display_name": "League of Legends Summoner Flex Rank",
                            "name": "summoner_flex_rank_check",
                            "description": "Check if the summoner flex rank is >, <, =, >=, <= a value",
                            "arguments": [
                                {
                                    "display_name": "Region",
                                    "name": "region",
                                    "type": "string",
                                    "default": "euw1",
                                    "options": [
                                        {
                                            "name": "euw1",
                                        },
                                        {
                                            "name": "na1",
                                        },
                                        {
                                            "name": "eun1",
                                        },
                                        {
                                            "name": "kr",
                                        }
                                    ],
                                }, {
                                    "display_name": "Summoner Name",
                                    "name": "summoner_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "Tier",
                                    "name": "tier",
                                    "type": "string",
                                    "default": "IRON",
                                    "options": [
                                        {
                                            "name": "IRON",
                                        },
                                        {
                                            "name": "BRONZE",
                                        },
                                        {
                                            "name": "SILVER",
                                        },
                                        {
                                            "name": "GOLD",
                                        },
                                        {
                                            "name": "PLATINUM",
                                        },
                                        {
                                            "name": "DIAMOND",
                                        },
                                        {
                                            "name": "MASTER",
                                        },
                                        {
                                            "name": "GRANDMASTER",
                                        },
                                        {
                                            "name": "CHALLENGER",
                                        },
                                    ],
                                }, {
                                    "display_name": "Rank",
                                    "name": "rank",
                                    "type": "string",
                                    "default": "IV",
                                    "options": [
                                        {
                                            "name": "IV",
                                        },
                                        {
                                            "name": "III",
                                        },
                                        {
                                            "name": "II",
                                        },
                                        {
                                            "name": "I",
                                        },
                                    ],
                                }
                            ],
                            "object_blueprint": {
                                "name": "summoner_flex_rank_check",
                                "region": None,
                                "summoner_name": None,
                                "operand": None,
                                "tier": None,
                                "rank": None,
                            }
                        }, {
                            "display_name": "League of Legends Summoner Solo Rank",
                            "name": "summoner_solo_rank_check",
                            "description": "Check if the summoner solo rank is >, <, =, >=, <= a value",
                            "arguments": [
                                {
                                    "display_name": "Region",
                                    "name": "region",
                                    "type": "string",
                                    "default": "euw1",
                                    "options": [
                                        {
                                            "name": "euw1",
                                        },
                                        {
                                            "name": "na1",
                                        },
                                        {
                                            "name": "eun1",
                                        },
                                        {
                                            "name": "kr",
                                        }
                                    ],
                                }, {
                                    "display_name": "Summoner Name",
                                    "name": "summoner_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "Tier",
                                    "name": "tier",
                                    "type": "string",
                                    "default": "IRON",
                                    "options": [
                                        {
                                            "name": "IRON",
                                        },
                                        {
                                            "name": "BRONZE",
                                        },
                                        {
                                            "name": "SILVER",
                                        },
                                        {
                                            "name": "GOLD",
                                        },
                                        {
                                            "name": "PLATINUM",
                                        },
                                        {
                                            "name": "DIAMOND",
                                        },
                                        {
                                            "name": "MASTER",
                                        },
                                        {
                                            "name": "GRANDMASTER",
                                        },
                                        {
                                            "name": "CHALLENGER",
                                        },
                                    ],
                                }, {
                                    "display_name": "Rank",
                                    "name": "rank",
                                    "type": "string",
                                    "default": "IV",
                                    "options": [
                                        {
                                            "name": "IV",
                                        },
                                        {
                                            "name": "III",
                                        },
                                        {
                                            "name": "II",
                                        },
                                        {
                                            "name": "I",
                                        },
                                    ],
                                }
                            ],
                            "object_blueprint": {
                                "name": "summoner_solo_rank_check",
                                "region": None,
                                "summoner_name": None,
                                "operand": None,
                                "tier": None,
                                "rank": None,
                            }
                        }, {
                            "display_name": "Summoner in Game",
                            "name": "summoner_in_game_check",
                            "description": "Check if the summoner is in game",
                            "arguments": [
                                {
                                    "display_name": "Region",
                                    "name": "region",
                                    "type": "string",
                                    "default": "euw1",
                                    "options": [
                                        {
                                            "name": "euw1",
                                        },
                                        {
                                            "name": "na1",
                                        },
                                        {
                                            "name": "eun1",
                                        },
                                        {
                                            "name": "kr",
                                        }
                                    ],
                                }, {
                                    "display_name": "Summoner Name",
                                    "name": "summoner_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "summoner_in_game_check",
                                "region": None,
                                "summoner_name": None,
                                "last_game_id": "",
                            }
                        }
                    ],
                    "reactions": [],
                }, {
                    "display_name": "Crypto Currencies",
                    "name": "crypto_currencies",
                    "icon": "https://cdn.iconscout.com/icon/free/png-256/ethereum-1-283135.png",
                    "authentication_required": None,
                    "actions": [
                        {
                            "display_name": "Ethereum gas price",
                            "name": "ethereum_gas_price",
                            "description": "Check the current ethereum gas price",
                            "arguments": [
                                {
                                    "display_name": "type",
                                    "name": "type",
                                    "type": "string",
                                    "default": "slow",
                                    "options": [
                                        {
                                            "name": "slow",
                                        },
                                        {
                                            "name": "normal",
                                        },
                                        {
                                            "name": "fast",
                                        },
                                        {
                                            "name": "instant",
                                        }
                                    ],
                                }, {
                                    "display_name": "operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "value",
                                    "name": "gwei",
                                    "type": "number",
                                    "default": "",
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "ethereum_gas_price",
                                "type": None,
                                "operand": None,
                                "gwei": None,
                            }
                        }, {
                            "display_name": "Crypto Pricing",
                            "name": "crypto_pricing",
                            "description": "Check the current price of a crypto currency",
                            "arguments": [
                                {
                                    "display_name": "Currency",
                                    "name": "currency",
                                    "type": "string",
                                    "default": "BTC",
                                    "options": [
                                        {
                                            "name": "BTC",
                                        },
                                        {
                                            "name": "ETH",
                                        },
                                        {
                                            "name": "BNB",
                                        },
                                        {
                                            "name": "ADA",
                                        },
                                        {
                                            "name": "XRP",
                                        },
                                        {
                                            "name": "LTC",
                                        },
                                        {
                                            "name": "SOL",
                                        }
                                    ],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "Value",
                                    "name": "value",
                                    "type": "number",
                                    "default": "",
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "crypto_pricing",
                                "currency": None,
                                "operand": None,
                                "value": None,
                            }
                        }
                    ],
                    "reactions": [],
                }, {
                    "display_name": "Weather",
                    "name": "weather",
                    "icon": "https://cdn.iconscout.com/icon/free/png-256/weather-296-1100758.png",
                    "authentication_required": None,
                    "actions": [
                        {
                            "display_name": "Weather",
                            "name": "weather",
                            "description": "Check the current weather of a city",
                            "arguments": [
                                {
                                    "display_name": "City",
                                    "name": "city",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Value",
                                    "name": "value",
                                    "type": "string",
                                    "default": "Rain",
                                    "options": [
                                        {
                                            "name": "Rain",
                                        },
                                        {
                                            "name": "Snow",
                                        },
                                        {
                                            "name": "Clear",
                                        },
                                        {
                                            "name": "Clouds",
                                        },
                                        {
                                            "name": "Drizzle",
                                        },
                                    ],
                                }
                            ],
                            "object_blueprint": {
                                "name": "weather",
                                "city": None,
                                "value": None,
                            }
                        }, {
                            "display_name": "Temperature",
                            "name": "temperature",
                            "description": "Check the current temperature of a city",
                            "arguments": [
                                {
                                    "display_name": "City",
                                    "name": "city",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "Value",
                                    "name": "value",
                                    "type": "number",
                                    "default": "",
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "temperature",
                                "city": None,
                                "operand": None,
                                "value": None,
                            }
                        }
                    ],
                }, {
                    "display_name": "Office",
                    "name": "office",
                    "icon": "https://global-uploads.webflow.com/5e45e7fa0ca16f6ed29e1e4e/600734520e30b01908569258_1200px-Microsoft_Office_logo_(2019%E2%80%93present).png",
                    "authentication_required": "office",
                    "params": [
                        {
                            "name": "token",
                            "type": "string",
                        }
                    ],
                    "api_url": "https://graph.microsoft.com/v1.0/me/",
                    "actions": [
                        {
                            "display_name": "Check office inbox",
                            "name": "check_office_inbox",
                            "description": "Check if there is an email in the user inbox that contains the given subject",
                            "arguments": [
                                {
                                    "display_name": "Subject",
                                    "name": "subject_to_check",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_office_inbox",
                                "subject_to_check": None,
                                "last_checked_subject": "",
                                "last_checked_datetime": "",
                            }
                        }
                    ],
                    "reactions": [
                        {
                            "display_name": "Send mail",
                            "name": "send_mail",
                            "description": "Send an email to a specific email address",
                            "arguments": [
                                {
                                    "display_name": "mail address",
                                    "name": "mail_to",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "subject",
                                    "name": "mail_subject",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Content",
                                    "name": "mail_content",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "send_mail",
                                "mail_to": None,
                                "mail_subject": None,
                                "mail_content": None,
                            }
                        }
                    ],
                }, {
                    "display_name": "Google",
                    "name": "google",
                    "icon": "https://jrs-technology.com/wp-content/uploads/2016/05/GoogleLOGO256x256.png",
                    "authentication_required": "google",
                    "params": [
                        {
                            "name": "token",
                            "type": "string",
                        }
                    ],
                    "api_url": "https://www.googleapis.com/oauth2/v3/userinfo",
                    "actions": [
                        {
                            "display_name": "Google Calendar Events",
                            "name": "check_google_calendar_events",
                            "description": "Check if there is an event in the user calendar (Let the date blank to check events everyday). Date need to be in the format YYYY-MM-DDT00:00:01Z",
                            "arguments": [
                                {
                                    "display_name": "Date",
                                    "name": "date",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_google_calendar_events",
                                "date": None,
                                "last_event_checked": "",
                            },
                        }
                    ],
                    "reactions": [],
                }, {
                    "display_name": "Facebook",
                    "name": "facebook",
                    "icon": "https://lorraineesport.fr/wp-content/uploads/2018/11/facebook.png",
                    "authentication_required": "facebook",
                    "params": [
                        {
                            "name": "token",
                            "type": "string",
                        }
                    ],
                    "api_url": "",
                    "actions": [
                        {
                            "display_name": "Check Birthday",
                            "name": "check_birthday",
                            "description": "Check if today is the user birthday (checks everyday)",
                            "arguments": [],
                            "object_blueprint": {
                                "name": "check_birthday",
                                "last_checked_birthday": "",
                            }
                        }, {
                            "display_name": "Check Facebook Number of friends",
                            "name": "check_facebook_number_of_friends",
                            "description": "Check if the user's friends number is >, <, =, >=, <= a value",
                            "arguments": [
                                {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "Value",
                                    "name": "friends",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_facebook_number_of_friends",
                                "friends": None,
                                "operand": None,
                            }
                        }
                    ],
                    "reactions": [],
                }, {
                    "display_name": "Intra Epitech",
                    "name": "epitech_intra",
                    "icon": "https://gitlab.clementdugal.fr/uploads/-/system/group/avatar/4/epitech.png",
                    "authentication_required": "epitech_intra",
                    "params": [
                        {
                            "name": "token",
                            "type": "string",
                        }
                    ],
                    "api_url": "https://intra.epitech.eu/admin/autolog",
                    "actions": [
                        {
                            "display_name": "Check Log time",
                            "name": "check_log_time",
                            "description": "Check if the user has logged more time than the given value",
                            "arguments": [
                                {
                                    "display_name": "Log time",
                                    "name": "log_time",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_log_time",
                                "log_time": None,
                            }
                        }, {
                            "display_name": "Check Credits",
                            "name": "check_credits",
                            "description": "Check if the user has more credits than the given value",
                            "arguments": [
                                {
                                    "display_name": "Credits",
                                    "name": "credits",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_credits",
                                "credits": None,
                            }
                        }, {
                            "display_name": "Check GPA",
                            "name": "check_gpa",
                            "description": "Check if the user has more GPA than the given value",
                            "arguments": [
                                {
                                    "display_name": "GPA",
                                    "name": "gpa",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_gpa",
                                "gpa": None,
                            }
                        }
                    ],
                    "reactions": [
                        {
                            "display_name": "Open Epitech Doors",
                            "name": "open_doors",
                            "description": "Open the doors of the Epitech Montpellier Campus",
                            "arguments": [
                                {
                                    "display_name": "name",
                                    "name": "door_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [
                                        {
                                            "name": "Meetup",
                                        }, {
                                            "name": "4eme",
                                        }, {
                                            "name": "HUB",
                                        }, {
                                            "name": "Foyer",
                                        }, {
                                            "name": "SM2",
                                        }, {
                                            "name": "SM1",
                                        }
                                    ],
                                }
                            ],
                            "object_blueprint": {
                                "name": "open_doors",
                                "door_name": None,
                            }
                        }
                    ],
                }, {
                    "display_name": "Discord",
                    "name": "discord",
                    "icon": "https://cdn.iconscout.com/icon/free/png-256/discord-2474808-2056094.png",
                    "params": [],
                    "api_url": "https://discord.gg/QaXPgcVg7H",
                    "authentication_required": None,
                    "actions": [],
                    "reactions": [
                        {
                            "display_name": "Send message",
                            "name": "discord_send_dm",
                            "description": "Send a message to a specific Discord user /!\ You must join this server first : https://discord.gg/QaXPgcVg7H",
                            "arguments": [
                                {
                                    "display_name": "User ID",
                                    "name": "discord_id",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Message",
                                    "name": "message",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "discord_send_dm",
                                "discord_id": None,
                                "message": None,
                            }
                        }
                    ],
                }, {
                    "display_name": "Twitch",
                    "name": "twitch",
                    "icon": "https://cdn.iconscout.com/icon/free/png-256/twitch-4054275-3352957.png",
                    "params": [],
                    "authentication_required": None,
                    "api_url": "",
                    "actions": [
                        {
                            "display_name": "Check if a user is streaming",
                            "name": "check_user_streaming",
                            "description": "Check if a user is streaming",
                            "arguments": [
                                {
                                    "display_name": "Username",
                                    "name": "user_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_user_streaming",
                                "user_name": None,
                                "checked": False,
                            }
                        }, {
                            "display_name": "Check user current viewers",
                            "name": "check_user_current_viewers",
                            "description": "Check the number of viewers for a given user",
                            "arguments": [
                                {
                                    "display_name": "Username",
                                    "name": "user_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        },
                                        {
                                            "name": "<",
                                        },
                                        {
                                            "name": "=",
                                        },
                                        {
                                            "name": ">=",
                                        },
                                        {
                                            "name": "<=",
                                        },
                                    ],
                                }, {
                                    "display_name": "Number",
                                    "name": "value",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_user_current_viewers",
                                "user_name": None,
                                "operand": None,
                                "value": None,
                                "checked": False,
                            }
                        }
                    ],
                    "reactions": [],
                }, {
                    "display_name": "Timer",
                    "name": "timer",
                    "icon": "https://www.meubles-magne.fr/wp-content/uploads/sites/7672/2019/07/wall-clock-1.png",
                    "authentication_required": None,
                    "params": [],
                    "api_url": "",
                    "actions": [
                        {
                            "display_name": "Timer",
                            "name": "timer_check",
                            "description": "Execute an action after a given time",
                            "arguments": [
                                {
                                    "display_name": "Time",
                                    "name": "offset",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "timer_check",
                                "offset": None,
                                "last_updated_at": "",
                            }
                        }
                    ],
                    "reactions": [],
                }, {
                    "display_name": "Reddit",
                    "name": "reddit",
                    "icon": "https://cdn.iconscout.com/icon/free/png-256/reddit-55-432536.png",
                    "authentication_required": "reddit",
                    "params": [
                        {
                            "name": "token",
                            "type": "string",
                        }
                    ],
                    "api_url": "https://www.reddit.com/api/v1/",
                    "actions": [
                        {
                            "display_name": "Check reddit subscribers",
                            "name": "check_reddit_subscribers",
                            "description": "Check the number of subscribers for a given subreddit",
                            "arguments": [
                                {
                                    "display_name": "Username",
                                    "name": "user",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        }, {
                                            "name": "<",
                                        }, {
                                            "name": "=",
                                        }, {
                                            "name": ">=",
                                        }, {
                                            "name": "<=",
                                        },
                                    ]
                                }, {
                                    "display_name": "number of subscribers",
                                    "name": "subscribers",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_reddit_subscribers",
                                "user": None,
                                "operand": None,
                                "subscribers": None,
                            },
                        }, {
                            "display_name": "Check reddit coins",
                            "name": "check_reddit_coins",
                            "description": "Check the number of coins you have",
                            "arguments": [
                                {
                                    "display_name": "number of coins",
                                    "name": "coins",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        }, {
                                            "name": "<",
                                        }, {
                                            "name": "=",
                                        }, {
                                            "name": ">=",
                                        }, {
                                            "name": "<=",
                                        },
                                    ]
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_reddit_coins",
                                "coins": None,
                                "operand": None,
                            },
                        }, {
                            "display_name": "Check first new subreddit name",
                            "name": "check_reddit_first_new_subreddit_name",
                            "description": "Check the name of the first new subreddit",
                            "arguments": [
                                {
                                    "display_name": "Subreddit name",
                                    "name": "subreddit_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": "start with",
                                    "options": [
                                        {
                                            "name": "start with",
                                        }, {
                                            "name": "not start with",
                                        }, {
                                            "name": "end with",
                                        }, {
                                            "name": "not end with",
                                        }
                                    ]
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_reddit_first_new_subreddit_name",
                                "subreddit_name": None,
                                "operand": None,
                            },
                        }, {
                            "display_name": "Check reddit karma",
                            "name": "check_reddit_karma",
                            "description": "Check the number of karma for a given user",
                            "arguments": [
                                {
                                    "display_name": "Username",
                                    "name": "user",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        }, {
                                            "name": "<",
                                        }, {
                                            "name": "=",
                                        }, {
                                            "name": ">=",
                                        }, {
                                            "name": "<=",
                                        }
                                    ]
                                }, {
                                    "display_name": "number of karma",
                                    "name": "karma",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_reddit_karma",
                                "user": None,
                                "operand": None,
                                "karma": None,
                            },
                        }, {
                            "display_name": "Check first popular subreddit name",
                            "name": "check_reddit_first_popular_subreddit_name",
                            "description": "Check the name of the first popular subreddit",
                            "arguments": [
                                {
                                    "display_name": "Subreddit name",
                                    "name": "subreddit_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": "start with",
                                    "options": [
                                        {
                                            "name": "start with",
                                        }, {
                                            "name": "not start with",
                                        }, {
                                            "name": "end with",
                                        }, {
                                            "name": "not end with",
                                        }
                                    ]
                                },
                            ],
                            "object_blueprint": {
                                "name": "check_reddit_first_popular_subreddit_name",
                                "subreddit_name": None,
                                "operand": None,
                            },
                        }, {
                            "display_name": "Check first gold subreddit name",
                            "name": "check_reddit_first_gold_subreddit_name",
                            "description": "Check the name of the first gold subreddit",
                            "arguments": [
                                {
                                    "display_name": "Subreddit name",
                                    "name": "subreddit_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": "start with",
                                    "options": [
                                        {
                                            "name": "start with",
                                        }, {
                                            "name": "not start with",
                                        }, {
                                            "name": "end with",
                                        }, {
                                            "name": "not end with",
                                        }
                                    ]
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_reddit_first_gold_subreddit_name",
                                "subreddit_name": None,
                                "operand": None,
                            }
                        }, {
                            "display_name": "Check first default subreddit name",
                            "name": "check_reddit_first_default_subreddit_name",
                            "description": "Check the name of the first default subreddit",
                            "arguments": [
                                {
                                    "display_name": "Subreddit name",
                                    "name": "subreddit_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": "start with",
                                    "options": [
                                        {
                                            "name": "start with",
                                        }, {
                                            "name": "not start with",
                                        }, {
                                            "name": "end with",
                                        }, {
                                            "name": "not end with",
                                        }
                                    ]
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_reddit_first_default_subreddit_name",
                                "subreddit_name": None,
                                "operand": None,
                            }
                        }, {
                            "display_name": "Check first new post name of subreddit",
                            "name": "check_reddit_first_new_name_by_subreddit",
                            "description": "Check the name of the first new post of a subreddit",
                            "arguments": [
                                {
                                    "display_name": "Subreddit",
                                    "name": "subreddit",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Post name",
                                    "name": "post_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": "start with",
                                    "options": [
                                        {
                                            "name": "start with",
                                        }, {
                                            "name": "end with",
                                        }, {
                                            "name": "not start with",
                                        }, {
                                            "name": "not end with",
                                        }
                                    ]
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_reddit_first_new_name_by_subreddit",
                                "subreddit": None,
                                "post_name": None,
                                "operand": None,
                            }
                        }, {
                            "display_name": "Check first hot post name of subreddit",
                            "name": "check_reddit_first_hot_name_by_subreddit",
                            "description": "Check the name of the first hot post of a subreddit",
                            "arguments": [
                                {
                                    "display_name": "Subreddit",
                                    "name": "subreddit",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Post name",
                                    "name": "post_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": "start with",
                                    "options": [
                                        {
                                            "name": "start with",
                                        }, {
                                            "name": "end with",
                                        }, {
                                            "name": "not start with",
                                        }, {
                                            "name": "not end with",
                                        }
                                    ]
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_reddit_first_hot_name_by_subreddit",
                                "subreddit": None,
                                "post_name": None,
                                "operand": None,
                            }
                        }, {
                            "display_name": "Check first top post name of subreddit",
                            "name": "check_reddit_first_top_name_by_subreddit",
                            "description": "Check the name of the first top post of a subreddit",
                            "arguments": [
                                {
                                    "display_name": "Subreddit",
                                    "name": "subreddit",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Post name",
                                    "name": "post_name",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": "start with",
                                    "options": [
                                        {
                                            "name": "start with",
                                        }, {
                                            "name": "end with",
                                        }, {
                                            "name": "not start with",
                                        }, {
                                            "name": "not end with",
                                        }
                                    ]
                                }
                            ],
                            "object_blueprint": {
                                "name": "check_reddit_first_top_name_by_subreddit",
                                "subreddit": None,
                                "post_name": None,
                                "operand": None,
                            }
                        }
                    ],
                    "reactions": [],
                }, {
                    "display_name": "Spotify",
                    "name": "spotify",
                    "icon": "https://static-s.aa-cdn.net/img/amazon/30600000199492/ec29c4fa192bbb9ff8ef5b8c5265b0d2?v=1",
                    "authentication_required": "spotify",
                    "params": [],
                    "api_url": "",
                    "actions": [
                        {
                            "display_name": "Spotify Artist Subscribers",
                            "name": "spotify_artist_subscribers",
                            "description": "Check if the number of subscribers for a given artist is >, <, =, >=, <= a given number",
                            "arguments": [
                                {
                                    "display_name": "Artist",
                                    "name": "artist",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        }, {
                                            "name": "<",
                                        }, {
                                            "name": "=",
                                        }, {
                                            "name": ">=",
                                        }, {
                                            "name": "<=",
                                        }
                                    ]  
                                }, {
                                    "display_name": "number of subscribers",
                                    "name": "subscribers",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "spotify_artist_subscribers",
                                "artist": None,
                                "operand": None,
                                "subscribers": None,
                            }
                        }, {
                            "display_name": "Spotify Artist Popularity",
                            "name": "spotify_artist_popularity",
                            "description": "Check the popularity of an artist",
                            "arguments": [
                                {
                                    "display_name": "Artist",
                                    "name": "artist",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        }, {
                                            "name": "<",
                                        }, {
                                            "name": "=",
                                        }, {
                                            "name": ">=",
                                        }, {
                                            "name": "<=",
                                        }
                                    ]
                                }, {
                                    "display_name": "popularity",
                                    "name": "popularity",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "spotify_artist_popularity",
                                "artist": None,
                                "operand": None,
                                "popularity": None,
                            }
                        }, {
                            "display_name": "Spotify Track Popularity",
                            "name": "spotify_track_popularity",
                            "description": "Check the popularity of a track",
                            "arguments": [
                                {
                                    "display_name": "Track",
                                    "name": "track",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": ">",
                                    "options": [
                                        {
                                            "name": ">",
                                        }, {
                                            "name": "<",
                                        }, {
                                            "name": "=",
                                        }, {
                                            "name": ">=",
                                        }, {
                                            "name": "<=",
                                        }
                                    ]
                                }, {
                                    "display_name": "popularity",
                                    "name": "popularity",
                                    "type": "number",
                                    "default": 0,
                                    "options": [],
                                }
                            ],
                            "object_blueprint": {
                                "name": "spotify_track_popularity",
                                "track": None,
                                "operand": None,
                                "popularity": None,
                            }
                        }, {
                            "display_name": "Spotify Last Release Artist Name",
                            "name": "spotify_last_release_check_artist_name",
                            "description": "Check if the given name is one of the author of a newly realeased track/album",
                            "arguments": [
                                {
                                    "display_name": "Artist",
                                    "name": "artist",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": "start with",
                                    "options": [
                                        {
                                            "name": "start with",
                                        }, {
                                            "name": "not start with",
                                        }, {
                                            "name": "=",
                                        }, {
                                            "name": "end with",
                                        }, {
                                            "name": "not end with",
                                        }
                                    ]
                                }
                            ],
                            "object_blueprint": {
                                "name": "spotify_last_release_check_artist_name",
                                "artist": None,
                                "operand": None,
                            }
                        }, {
                            "display_name": "Spotify Last Country Release Artist Name",
                            "name": "spotify_last_release_check_artist_name_by_country_code",
                            "description": "Check if the given name is one of the author of a newly realeased track/album in the given country",
                            "arguments": [
                                {
                                    "display_name": "Artist",
                                    "name": "artist",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Country Code",
                                    "name": "country_code",
                                    "type": "string",
                                    "default": "",
                                    "options": [],
                                }, {
                                    "display_name": "Operand",
                                    "name": "operand",
                                    "type": "string",
                                    "default": "start with",
                                    "options": [
                                        {
                                            "name": "start with",
                                        }, {
                                            "name": "not start with",
                                        }, {
                                            "name": "=",
                                        }, {
                                            "name": "end with",
                                        }, {
                                            "name": "not end with",
                                        }
                                    ]
                                }
                            ],
                            "object_blueprint": {
                                "name": "spotify_last_release_check_artist_name_by_country_code",
                                "artist": None,
                                "country_code": None,
                                "operand": None,
                            }
                        }
                    ],
                    "reactions": [],
                }
            ]
        }
    }