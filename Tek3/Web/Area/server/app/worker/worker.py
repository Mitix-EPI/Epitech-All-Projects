import time
import json

from app.services.cryptos.cryptos import CryptosActions
from app.services.farmersworld.farmersworld import FarmersWorldActions
from app.services.league_of_legends.league_of_legends import LeagueOfLegendsActions
from app.services.weather.weather import WeatherActions
from app.services.intra.intra_epitech import IntraEpitechActions
from app.services.google.google import GoogleActions
from app.services.timer.timer import TimerActions
from app.services.twitch.twitch import TwitchActions
from app.services.office.office import OfficeActions
from app.services.reddit.reddit import RedditActions
from app.services.twitch.twitch import TwitchActions
from app.services.facebook.facebook import FacebookActions
from app.services.spotify.spotify import SpotifyActions

from app.reactions.send_mail import SendMail
from app.reactions.doors import Doors
from app.reactions.discord_bot import DisBot

from app.database.ActionsReactions import ActionsReactionsDatabase
from app.database.UserInformations import UserInformations

class Worker:
    def __init__(self) -> None:
        ###############################################################
        #                           ACTIONS                           #
        ###############################################################
        self.__farmersworld__ = FarmersWorldActions()
        self.__league_of_legends__ = LeagueOfLegendsActions()
        self.__cryptos__ = CryptosActions()
        self.__weather__ = WeatherActions()
        self.__intra_epitech__ = IntraEpitechActions()
        self.__twitch__ = TwitchActions()
        self.__reddit__ = RedditActions()
        self.__spotify__ = SpotifyActions()
        self.__timer__ = TimerActions()
        self.__google__ = GoogleActions()
        self.__office__ = OfficeActions()
        self.__facebook__ = FacebookActions()

        ###############################################################
        #                           REACTIONS                        #
        ###############################################################
        self.__send_mail__ = SendMail()
        self.__doors__ = Doors()
        self.__discord__ = DisBot() 
        self.index = 0
        self.user_infos_db = UserInformations()

    def execute_action(self, action, reaction, user_id: int, action_id: int) -> bool:
        print('[worker3]: executing action...', flush=True)
        _test = action['name']
        print(f'[worker3]: action == {_test}', flush=True)

        if action['name'] == "temperature" :
            return self.__weather__.temperature_action(action['city'], action['operand'], action['value'])
        elif action['name'] == "weather" :
            return self.__weather__.weather_action(action['city'], action['value'])
        elif action['name'] == "summoner_level_check" :
            return self.__league_of_legends__.summoner_level(action['region'], action['summoner_name'], action['operand'], action['level'])
        elif action['name'] == "summoner_flex_rank_check" :
            return self.__league_of_legends__.summoner_flex_rank(action['region'], action['summoner_name'], action['operand'], action['tier'], action['rank'])
        elif action['name'] == "summoner_solo_rank_check" :
            return self.__league_of_legends__.summoner_solo_rank(action['region'], action['summoner_name'], action['operand'], action['tier'], action['rank'])
        elif action['name'] == "summoner_in_game_check" :
            status, action['last_game_id'] = self.__league_of_legends__.summoner_in_game(action['region'], action['summoner_name'], action['last_game_id'])
            action_reaction_db = ActionsReactionsDatabase()
            action_reaction_db.update_actions_reactions(user_id, action_id, json.dumps(action), json.dumps(reaction))
            print(f'[worker3]: action == {_test} || status === {status}', flush=True)
            return status
        elif action['name'] == "ethereum_gas_price" :
            return self.__cryptos__.eth_gas_action(action['type'], action['operand'], action['gwei'])
        elif action['name'] == "crypto_pricing" :
            return self.__cryptos__.crypto_pricing_action(action['currency'], action['operand'], action['value'])
        elif action['name'] == "fww_price_check" :
            return self.__farmersworld__.fww_price_action_refresh(action['operand'], action['value'])
        elif action['name'] == "fwf_price_check" :
            return self.__farmersworld__.fwf_price_action_refresh(action['operand'], action['value'])
        elif action['name'] == "fwg_price_check" :
            return self.__farmersworld__.fwg_price_action_refresh(action['operand'], action['value'])
        elif action['name'] == "wax_price_check" :
            return self.__farmersworld__.wax_usd_price_action_refresh(action['operand'], action['value'])
        elif action['name'] == "fees_price_check" :
            return self.__farmersworld__.fees_action_refresh(action['operand'], action['value'])
        elif action['name'] == "check_user_streaming" :
            status, action['checked'] = self.__twitch__.check_user_streaming(action['user_name'], action['checked'])
            action_reaction_db = ActionsReactionsDatabase()
            action_reaction_db.update_actions_reactions(user_id, action_id, json.dumps(action), json.dumps(reaction))
            print(f'[worker3]: action == {_test} || status === {status}', flush=True)
            return status
        elif action['name'] == "check_user_current_viewers" :
            status, action['checked'] = self.__twitch__.check_user_current_viewers(action['user_name'], action['operand'], action['value'], action['checked'])
            action_reaction_db = ActionsReactionsDatabase()
            action_reaction_db.update_actions_reactions(user_id, action_id, json.dumps(action), json.dumps(reaction))
            print(f'[worker3]: action == {_test} || status === {status}', flush=True)
            return status
        elif action['name'] == "timer_check" :
            status, action['last_updated_at'] = self.__timer__.timer_action(action['last_updated_at'], action['offset'])
            action_reaction_db = ActionsReactionsDatabase()
            action_reaction_db.update_actions_reactions(user_id, action_id, json.dumps(action), json.dumps(reaction))
            print(f'[worker3]: action == {_test} || status === {status}', flush=True)
            return status
        elif action['name'] == "check_office_inbox" :
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, 'office_token')
            if (token == "") :
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            print(f'[worker3]: office_token == {token}', flush=True)
            status, action['last_checked_subject'], action['last_checked_datetime'] = self.__office__.check_inbox_specific_message(token, action['subject_to_check'], action['last_checked_subject'], action['last_checked_datetime'])
            action_reaction_db = ActionsReactionsDatabase()
            action_reaction_db.update_actions_reactions(user_id, action_id, json.dumps(action), json.dumps(reaction))
            return status
        elif action['name'] == "check_google_calendar_events":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, 'google_token')
            if (token == "") :
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            status, action['last_event_checked'] = self.__google__.check_calendar_events(token, action['date'], action['last_event_checked'])
            action_reaction_db = ActionsReactionsDatabase()
            action_reaction_db.update_actions_reactions(user_id, action_id, json.dumps(action), json.dumps(reaction))
            return status
        elif action['name'] == "check_reddit_coins":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "reddit_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            print(f'[worker3]: reddit_token == {token}', flush=True)
            status = self.__reddit__.check_coins(token, action["coins"], action['operand'])
            return status
        elif action['name'] == "check_reddit_subscribers":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "reddit_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            print(f'[worker3]: reddit_token == {token}', flush=True)
            status = self.__reddit__.check_subscribers(token, action["user"], action["subscribers"], action['operand'])
            return status
        elif action['name'] == "check_reddit_karma":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "reddit_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            print(f'[worker3]: reddit_token == {token}', flush=True)
            status = self.__reddit__.check_karma(token, action["user"], action["karma"], action['operand'])
            return status
        elif action['name'] == "check_reddit_first_new_subreddit_name":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "reddit_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            print(f'[worker3]: reddit_token == {token}', flush=True)
            status = self.__reddit__.get_last_new_subreddit_name(token, action["subreddit_name"], action['operand'])
            return status
        elif action['name'] == "check_reddit_first_popular_subreddit_name":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "reddit_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            print(f'[worker3]: reddit_token == {token}', flush=True)
            status = self.__reddit__.get_last_popular_subreddit_name(token, action["subreddit_name"], action['operand'])
            return status
        elif action['name'] == "check_reddit_first_gold_subreddit_name":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "reddit_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            print(f'[worker3]: reddit_token == {token}', flush=True)
            status = self.__reddit__.get_last_gold_subreddit_name(token, action["subreddit_name"], action['operand'])
            return status
        elif action['name'] == "check_reddit_first_default_subreddit_name":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "reddit_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            print(f'[worker3]: reddit_token == {token}', flush=True)
            status = self.__reddit__.get_last_default_subreddit_name(token, action["subreddit_name"], action['operand'])
            return status
        elif action['name'] == "check_reddit_first_new_name_by_subreddit":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "reddit_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            print(f'[worker3]: reddit_token == {token}', flush=True)
            status = self.__reddit__.get_first_new_by_subreddit_name(token, action["subreddit"], action["post_name"], action['operand'])
            return status
        elif action['name'] == "check_reddit_first_hot_name_by_subreddit":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "reddit_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            print(f'[worker3]: reddit_token == {token}', flush=True)
            status = self.__reddit__.get_first_hot_by_subreddit_name(token, action["subreddit"], action["post_name"], action['operand'])
            return status
        elif action['name'] == "check_reddit_first_top_name_by_subreddit":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "reddit_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            print(f'[worker3]: reddit_token == {token}', flush=True)
            status = self.__reddit__.get_first_top_by_subreddit_name(token, action["subreddit"], action["post_name"], action['operand'])
            return status
        elif action['name'] == "check_log_time" :
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "epitech_intra_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            return self.__intra_epitech__.getLogTime(token, action['log_time'])
        elif action['name'] == "check_credits" :
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "epitech_intra_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            return self.__intra_epitech__.getCredits(token, action["credits"])
        elif action['name'] == "check_gpa" :
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "epitech_intra_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            return self.__intra_epitech__.getLogTime(token, action['gpa'])
        elif action['name'] == "check_birthday" :
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "facebook_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            status, action['last_checked_birthday'] = self.__facebook__.check_birthday(token, action['last_checked_birthday'])
            action_reaction_db = ActionsReactionsDatabase()
            action_reaction_db.update_actions_reactions(user_id, action_id, json.dumps(action), json.dumps(reaction))
            return status
        elif action['name'] == "check_facebook_number_of_friends" :
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "facebook_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            return self.__facebook__.check_friends(token, action['friends'], action['operand'])
        elif action['name'] == "spotify_artist_subscribers":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "spotify_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            status = self.__spotify__.check_artist_subscribers(token, action["artist"], action["subscribers"], action["operand"])
            return status
        elif action['name'] == "spotify_artist_popularity":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "spotify_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            status = self.__spotify__.check_artist_popularity(token, action["artist"], action["popularity"], action["operand"])
            return status
        elif action['name'] == "spotify_track_popularity":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "spotify_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            status = self.__spotify__.check_track_popularity(token, action["track"], action["popularity"], action["operand"])
            return status
        elif action['name'] == "spotify_last_release_check_artist_name":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "spotify_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            status = self.__spotify__.check_last_release_artist_name(token, action["artist"], action["operand"])
            return status
        elif action['name'] == "spotify_last_release_check_artist_name_by_country_code":
            stats, token = self.user_infos_db.get_user_specific_information_by_id(user_id, "spotify_token")
            if (token == ""):
                print(f'[worker3]: no token found for user {user_id}', flush=True)
                return False
            status = self.__spotify__.check_artist_subscribers(token, action["country_code"], action["artist"], action["operand"])
            return status
        return False

    def execute_reaction(self, reaction, user_id: int) -> bool:
        if reaction['name'] == "send_mail" :
            status, token = self.user_infos_db.get_user_specific_information_by_id(user_id, 'office_token')
            print(f'[worker2]: token == {token}', flush=True)
            if (token == "") :
                print(f'[worker2]: no token found for user {user_id}', flush=True)
                return False
            return self.__send_mail__.send_mail_office(token, reaction['mail_to'], reaction['mail_subject'], reaction['mail_content'])
        elif reaction['name'] == "open_doors" :
            status, token = self.user_infos_db.get_user_specific_information_by_id(user_id, 'epitech_intra_token')
            print(f'[worker2]: token == {token}', flush=True)
            if (token == "") :
                print(f'[worker2]: no token found for user {user_id}', flush=True)
                return False
            return self.__doors__.doors_reaction(token, reaction['door_name'])
        elif reaction['name'] == "test_print" :
            _test2 = reaction['value']
            print(f'[worker]: test_print "{_test2}"', flush=True)
            return True
        elif reaction['name'] == "discord_send_dm":
            return self.__discord__.send_message(reaction['discord_id'], reaction['message'])
        return False

    def worker(self) -> None:
        print('[worker]: working...')
        actions_reactions_db = ActionsReactionsDatabase()
        actions_reactions = actions_reactions_db.get_all_actions_reactions()
        for action_reaction in actions_reactions:
            print('[worker2]: action_reaction:', action_reaction, flush=True)
            action_id = int(action_reaction[0])
            user_id = int(action_reaction[1])
            my_action = json.loads(action_reaction[2])
            my_reaction = json.loads(action_reaction[3])
            if self.execute_action(my_action, my_reaction, user_id, action_id) == True:
                print(f'[worker2]: executing {my_reaction["name"]}', flush=True)
                ret = self.execute_reaction(my_reaction, user_id)
                if ret == False:
                    print(f'[worker2]: reaction {my_reaction["name"]} failed', flush=True)
                else:
                    print(f'[worker2]: reaction {my_reaction["name"]} successfully executed', flush=True)


        # actions_reactions_db.add_actions_reactions(1, f"action {self.index}", f"reaction {self.index}")
        self.index += 1

    def working_loop(self) -> None:
        print('[worker]: welcome to the working loop...', flush=True)
        while True:
            self.worker()
            # wait 5 minutes and then restart the loop
            time.sleep(5*60)