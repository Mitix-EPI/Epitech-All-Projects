import requests

class CryptosActions:
    def __init__(self) -> None:
        self.eth_gas_url = 'http://ethgas.watch/api/gas'
        self.crypto_url = 'https://api.coingecko.com/api/v3/coins/markets?vs_currency=usd&order=market_cap_desc&per_page=100&page=1&sparkline=false'

    #################################################################################################
    #                                            ACTIONS                                            #
    #################################################################################################

    def eth_gas_action(self, type, operand, gwei) -> bool:
        r = requests.get(self.eth_gas_url)
        r = r.json()

        if type == 'slow':
            _eth_gas_slow = r['slow']['gwei']
            if operand == '>':
                return _eth_gas_slow > gwei
            elif operand == '<':
                return _eth_gas_slow < gwei
            elif operand == '=':
                return _eth_gas_slow == gwei
            elif operand == '>=':
                return _eth_gas_slow >= gwei
            elif operand == '<=':
                return _eth_gas_slow <= gwei
            else:
                return False
        elif type == 'normal':
            _eth_gas_normal = r['normal']['gwei']
            if operand == '>':
                return _eth_gas_normal > gwei
            elif operand == '<':
                return _eth_gas_normal < gwei
            elif operand == '=':
                return _eth_gas_normal == gwei
            elif operand == '>=':
                return _eth_gas_normal >= gwei
            elif operand == '<=':
                return _eth_gas_normal <= gwei
            else:
                return False
        elif type == 'fast':
            _eth_gas_fast = r['fast']['gwei']
            if operand == '>':
                return _eth_gas_fast > gwei
            elif operand == '<':
                return _eth_gas_fast < gwei
            elif operand == '=':
                return _eth_gas_fast == gwei
            elif operand == '>=':
                return _eth_gas_fast >= gwei
            elif operand == '<=':
                return _eth_gas_fast <= gwei
            else:
                return False
        elif type == 'instant':
            _eth_gas_instant = r['instant']['gwei']
            if operand == '>':
                return _eth_gas_instant > gwei
            elif operand == '<':
                return _eth_gas_instant < gwei
            elif operand == '=':
                return _eth_gas_instant == gwei
            elif operand == '>=':
                return _eth_gas_instant >= gwei
            elif operand == '<=':
                return _eth_gas_instant <= gwei
            else:
                return False
        else:
            return False

    def crypto_pricing_action(self, crypto, operand, value) -> bool:
        r = requests.get(self.crypto_url)
        r = r.json()

        if crypto == 'BTC':
            btc = filter(lambda x: x['symbol'] == 'btc', r)
            if operand == '>':
                return btc[0]['current_price'] > value
            elif operand == '<':
                return btc[0]['current_price'] < value
            elif operand == '=':
                return btc[0]['current_price'] == value
            elif operand == '>=':
                return btc[0]['current_price'] >= value
            elif operand == '<=':
                return btc[0]['current_price'] <= value
            else:
                return False
        elif crypto == 'ETH':
            eth = filter(lambda x: x['symbol'] == 'eth', r)
            if operand == '>':
                return eth[0]['current_price'] > value
            elif operand == '<':
                return eth[0]['current_price'] < value
            elif operand == '=':
                return eth[0]['current_price'] == value
            elif operand == '>=':
                return eth[0]['current_price'] >= value
            elif operand == '<=':
                return eth[0]['current_price'] <= value
            else:
                return False
        elif crypto == 'BNB':
            bnb = filter(lambda x: x['symbol'] == 'bnb', r)
            if operand == '>':
                return bnb[0]['current_price'] > value
            elif operand == '<':
                return bnb[0]['current_price'] < value
            elif operand == '=':
                return bnb[0]['current_price'] == value
            elif operand == '>=':
                return bnb[0]['current_price'] >= value
            elif operand == '<=':
                return bnb[0]['current_price'] <= value
            else:
                return False
        elif crypto == 'ADA':
            ada = filter(lambda x: x['symbol'] == 'ada', r)
            if operand == '>':
                return ada[0]['current_price'] > value
            elif operand == '<':
                return ada[0]['current_price'] < value
            elif operand == '=':
                return ada[0]['current_price'] == value
            elif operand == '>=':
                return ada[0]['current_price'] >= value
            elif operand == '<=':
                return ada[0]['current_price'] <= value
            else:
                return False
        elif crypto == 'XRP':
            xrp = filter(lambda x: x['symbol'] == 'xrp', r)
            if operand == '>':
                return xrp[0]['current_price'] > value
            elif operand == '<':
                return xrp[0]['current_price'] < value
            elif operand == '=':
                return xrp[0]['current_price'] == value
            elif operand == '>=':
                return xrp[0]['current_price'] >= value
            elif operand == '<=':
                return xrp[0]['current_price'] <= value
            else:
                return False
        elif crypto == 'LTC':
            ltc = filter(lambda x: x['symbol'] == 'ltc', r)
            if operand == '>':
                return ltc[0]['current_price'] > value
            elif operand == '<':
                return ltc[0]['current_price'] < value
            elif operand == '=':
                return ltc[0]['current_price'] == value
            elif operand == '>=':
                return ltc[0]['current_price'] >= value
            elif operand == '<=':
                return ltc[0]['current_price'] <= value
            else:
                return False
        elif crypto == 'SOL':
            sol = filter(lambda x: x['symbol'] == 'sol', r)
            if operand == '>':
                return sol[0]['current_price'] > value
            elif operand == '<':
                return sol[0]['current_price'] < value
            elif operand == '=':
                return sol[0]['current_price'] == value
            elif operand == '>=':
                return sol[0]['current_price'] >= value
            elif operand == '<=':
                return sol[0]['current_price'] <= value
            else:
                return False
        return False