import requests
import os

class LeagueOfLegendsActions:
    def __init__(self) -> None:
        self.summoner_endpoint = '/summoner/v4/summoners/by-name/'
        self.live_game_endpoint = '/spectator/v4/active-games/by-summoner/'
        self.summoner_league_entries_endpoint = '/league/v4/entries/by-summoner/'
        self.api_url = '.api.riotgames.com/lol'
        self.protocol = 'https://'
        self.api_key = os.getenv('RIOT_API')

    def convert_rank(self, rank) -> int:
        if rank == 'I':
            return 5
        elif rank == 'II':
            return 4
        elif rank == 'III':
            return 3
        elif rank == 'IV':
            return 2
        elif rank == 'V':
            return 1
        else:
            return 0
    
    def convert_tier(self, tier) -> int:
        if tier == 'IRON':
            return 1
        elif tier == 'BRONZE':
            return 2
        elif tier == 'SILVER':
            return 3
        elif tier == 'GOLD':
            return 4
        elif tier == 'PLATINUM':
            return 5
        elif tier == 'DIAMOND':
            return 6
        elif tier == 'MASTER':
            return 7
        elif tier == 'GRANDMASTER':
            return 8
        elif tier == 'CHALLENGER':
            return 9
        else:
            return 0

    #################################################################################################
    #                                            ACTIONS                                            #
    #################################################################################################

    def summoner_level(self, region, summoner_name, operand, value) -> bool:
        url = self.protocol + region + self.api_url + self.summoner_endpoint + summoner_name
        r = requests.get(url, headers={
            'X-Riot-Token': self.api_key
        })
        r = r.json()

        if operand == '>':
            return r['summonerLevel'] > value
        elif operand == '<':
            return r['summonerLevel'] < value
        elif operand == '=':
            return r['summonerLevel'] == value
        elif operand == '>=':
            return r['summonerLevel'] >= value
        elif operand == '<=':
            return r['summonerLevel'] <= value
        else:
            return False

    def summoner_flex_rank(self, region, summoner_name, operand, tier, rank) -> bool:
        url = self.protocol + region + self.api_url + self.summoner_endpoint + summoner_name

        r = requests.get(url, headers={
            'X-Riot-Token': self.api_key
        })
        r = r.json()
        summoner_id = r['id']

        url = self.protocol + region + self.api_url + self.summoner_league_entries_endpoint + summoner_id
        r = requests.get(url, headers={
            'X-Riot-Token': self.api_key
        })
        r = r.json()
        flex_rank = {}
        for league in r:
            if league['queueType'] == 'RANKED_FLEX_SR':
                flex_rank = league
                break
        if flex_rank == {}:
            return False
        
        if operand == '>':
            if self.convert_tier(tier) > self.convert_tier(flex_rank['tier']):
                return True
            if self.convert_tier(tier) >= self.convert_tier(flex_rank['tier']) and self.convert_rank(rank) > self.convert_rank(flex_rank['rank']):
                return True
            else:
                return False
        elif operand == '<':
            if self.convert_tier(tier) < self.convert_tier(flex_rank['tier']):
                return True
            if self.convert_tier(tier) <= self.convert_tier(flex_rank['tier']) and self.convert_rank(rank) < self.convert_rank(flex_rank['rank']):
                return True
            else:
                return False
        elif operand == '=':
            if self.convert_tier(tier) == self.convert_tier(flex_rank['tier']) and self.convert_rank(rank) == self.convert_rank(flex_rank['rank']):
                return True
            else:
                return False
        elif operand == '>=':
            if self.convert_tier(tier) >= self.convert_tier(flex_rank['tier']) and self.convert_rank(rank) >= self.convert_rank(flex_rank['rank']):
                return True
            else:
                return False
        elif operand == '<=':
            if self.convert_tier(tier) <= self.convert_tier(flex_rank['tier']) and self.convert_rank(rank) <= self.convert_rank(flex_rank['rank']):
                return True
            else:
                return False
        else:
            return False

    def summoner_solo_rank(self, region, summoner_name, operand, tier, rank) -> bool:
        url = self.protocol + region + self.api_url + self.summoner_endpoint + summoner_name

        r = requests.get(url, headers={
            'X-Riot-Token': self.api_key
        })
        r = r.json()
        summoner_id = r['id']

        url = self.protocol + region + self.api_url + self.summoner_league_entries_endpoint + summoner_id
        r = requests.get(url, headers={
            'X-Riot-Token': self.api_key
        })
        r = r.json()
        solo_rank = {}
        for league in r:
            if league['queueType'] == 'RANKED_SOLO_5x5':
                solo_rank = league
                break
        if solo_rank == {}:
            return False
        
        if operand == '>':
            if self.convert_tier(tier) > self.convert_tier(solo_rank['tier']):
                return True
            if self.convert_tier(tier) >= self.convert_tier(solo_rank['tier']) and self.convert_rank(rank) > self.convert_rank(solo_rank['rank']):
                return True
            else:
                return False
        elif operand == '<':
            if self.convert_tier(tier) < self.convert_tier(solo_rank['tier']):
                return True
            if self.convert_tier(tier) <= self.convert_tier(solo_rank['tier']) and self.convert_rank(rank) < self.convert_rank(solo_rank['rank']):
                return True
            else:
                return False
        elif operand == '=':
            if self.convert_tier(tier) == self.convert_tier(solo_rank['tier']) and self.convert_rank(rank) == self.convert_rank(solo_rank['rank']):
                return True
            else:
                return False
        elif operand == '>=':
            if self.convert_tier(tier) >= self.convert_tier(solo_rank['tier']) and self.convert_rank(rank) >= self.convert_rank(solo_rank['rank']):
                return True
            else:
                return False
        elif operand == '<=':
            if self.convert_tier(tier) <= self.convert_tier(solo_rank['tier']) and self.convert_rank(rank) <= self.convert_rank(solo_rank['rank']):
                return True
            else:
                return False
        else:
            return False

    def summoner_in_game(self, region, summoner_name, last_game_id):
        url1 = self.protocol + region + self.api_url + self.summoner_endpoint + summoner_name
        url2 = self.protocol + region + self.api_url + self.live_game_endpoint

        r = requests.get(url1, headers={
            'X-Riot-Token': self.api_key
        })
        r = r.json()
        print(f'r ===== {r}')
        summoner_id = r['id']

        r = requests.get(url2 + summoner_id, headers={
            'X-Riot-Token': self.api_key
        })
        if r.status_code == 404:
            print(f'[summoner_in_game]: no game found')
            return False, last_game_id
        r = r.json()
        if r['gameId'] == last_game_id:
            return False, last_game_id
        return True, r['gameId']