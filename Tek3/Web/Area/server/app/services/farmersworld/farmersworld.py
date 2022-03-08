import requests

class FarmersWorldActions:
    def __init__(self) -> None:
        self.fww_url = 'https://wax.alcor.exchange/api/markets/104'
        self.fwf_url = 'https://wax.alcor.exchange/api/markets/105'
        self.fwg_url = 'https://wax.alcor.exchange/api/markets/106'
        self.wax_usd_url = 'https://api.coingecko.com/api/v3/simple/price?ids=wax&vs_currencies=usd&include_24hr_change=true'
        self.fees_url = 'https://wax.pink.gg/v1/chain/get_table_rows'

        self.fww_price = 0
        self.fwf_price = 0
        self.fwg_price = 0
        self.wax_usd_price = 0
        self.fees = 0

        try:
            r = requests.get(self.fww_url)
            r = r.json()
            self.fww_price = r['last_price']
        except:
            pass

        try:
            r = requests.get(self.fwf_url)
            r = r.json()
            self.fwf_price = r['last_price']
        except:
            pass

        try:
            r = requests.get(self.fwg_url)
            r = r.json()
            self.fwg_price = r['last_price']
        except:
            pass

        try:
            r = requests.get(self.wax_usd_url)
            r = r.json()
            self.wax_usd_price = r['wax']['usd']
        except:
            pass

        try:
            r = requests.post(self.fees_url, json={
                "json": "true",
                "code": "farmersworld",
                "scope": "farmersworld",
                "table": "config",
                "table_key": "",
                "lower_bound": "",
                "upper_bound": "",
                "index_position": 1,
                "key_type": "",
                "limit": 1,
                "reverse": "false",
                "show_payer": "false"
            })
            r = r.json()
            print(r)
            self.fees = r['rows'][0]['fee']
        except:
            pass    


    def refresh_values(self) -> None :
        try:
            r = requests.get(self.fww_url)
            r = r.json()
            self.fww_price = r['last_price']
        except:
            pass

        try:
            r = requests.get(self.fwf_url)
            r = r.json()
            self.fwf_price = r['last_price']
        except:
            pass

        try:
            r = requests.get(self.fwg_url)
            r = r.json()
            self.fwg_price = r['last_price']
        except:
            pass

        try:
            r = requests.get(self.wax_usd_url)
            r = r.json()
            self.wax_usd_price = r['wax']['usd']
        except:
            pass

        try:
            r = requests.post(self.fees_url, json={
                "json": "true",
                "code": "farmersworld",
                "scope": "farmersworld",
                "table": "config",
                "table_key": "",
                "lower_bound": "",
                "upper_bound": "",
                "index_position": 1,
                "key_type": "",
                "limit": 1,
                "reverse": "false",
                "show_payer": "false"
            })
            r = r.json()
            self.fees = r['rows'][0]['fees']
        except:
            pass

    #################################################################################################
    #                                            ACTIONS                                            #
    #################################################################################################

    def fww_price_action(self, operand, value) -> bool :
        if operand == '>':
            return self.fww_price > value
        elif operand == '<':
            return self.fww_price < value
        elif operand == '=':
            return self.fww_price == value
        elif operand == '>=':
            return self.fww_price >= value
        elif operand == '<=':
            return self.fww_price <= value
        else:
            return False

    def fwf_price_action(self, operand, value) -> bool :
        if operand == '>':
            return self.fwf_price > value
        elif operand == '<':
            return self.fwf_price < value
        elif operand == '=':
            return self.fwf_price == value
        elif operand == '>=':
            return self.fwf_price >= value
        elif operand == '<=':
            return self.fwf_price <= value
        else:
            return False
        
    def fwg_price_action(self, operand, value) -> bool :
        if operand == '>':
            return self.fwg_price > value
        elif operand == '<':
            return self.fwg_price < value
        elif operand == '=':
            return self.fwg_price == value
        elif operand == '>=':
            return self.fwg_price >= value
        elif operand == '<=':
            return self.fwg_price <= value
        else:
            return False
    
    def wax_usd_price_action(self, operand, value) -> bool :
        if operand == '>':
            return self.wax_usd_price > value
        elif operand == '<':
            return self.wax_usd_price < value
        elif operand == '=':
            return self.wax_usd_price == value
        elif operand == '>=':
            return self.wax_usd_price >= value
        elif operand == '<=':
            return self.wax_usd_price <= value
        else:
            return False
        
    def fees_action(self, operand, value) -> bool :
        if operand == '>':
            return self.fees > value
        elif operand == '<':
            return self.fees < value
        elif operand == '=':
            return self.fees == value
        elif operand == '>=':
            return self.fees >= value
        elif operand == '<=':
            return self.fees <= value
        else:
            return False

    #################################################################################################
    #                                            ACTIONS 2                                          #
    #################################################################################################

    def fww_price_action_refresh(self, operand, value) -> bool :
        r = requests.get(self.fww_url)
        r = r.json()

        _fww_price = r['last_price']

        if operand == '>':
            return _fww_price > value
        elif operand == '<':
            return _fww_price < value
        elif operand == '=':
            return _fww_price == value
        elif operand == '>=':
            return _fww_price >= value
        elif operand == '<=':
            return _fww_price <= value
        else:
            return False

    def fwf_price_action_refresh(self, operand, value) -> bool :
        r = requests.get(self.fwf_url)
        r = r.json()

        _fwf_price = r['last_price']

        if operand == '>':
            return _fwf_price > value
        elif operand == '<':
            return _fwf_price < value
        elif operand == '=':
            return _fwf_price == value
        elif operand == '>=':
            return _fwf_price >= value
        elif operand == '<=':
            return _fwf_price <= value
        else:
            return False
        
    def fwg_price_action_refresh(self, operand, value) -> bool :
        r = requests.get(self.fwg_url)
        r = r.json()

        _fwg_price = r['last_price']

        if operand == '>':
            return _fwg_price > value
        elif operand == '<':
            return _fwg_price < value
        elif operand == '=':
            return _fwg_price == value
        elif operand == '>=':
            return _fwg_price >= value
        elif operand == '<=':
            return _fwg_price <= value
        else:
            return False
    
    def wax_usd_price_action_refresh(self, operand, value) -> bool :
        r = requests.get(self.wax_usd_url)
        r = r.json()

        _wax_usd_price = r['wax']['usd']

        if operand == '>':
            return _wax_usd_price > value
        elif operand == '<':
            return _wax_usd_price < value
        elif operand == '=':
            return _wax_usd_price == value
        elif operand == '>=':
            return _wax_usd_price >= value
        elif operand == '<=':
            return _wax_usd_price <= value
        else:
            return False
        
    def fees_action_refresh(self, operand, value) -> bool :
        r = requests.get(self.fees_url)
        r = r.json()

        _fees = r['rows'][0]['fees']

        if operand == '>':
            return _fees > value
        elif operand == '<':
            return _fees < value
        elif operand == '=':
            return _fees == value
        elif operand == '>=':
            return _fees >= value
        elif operand == '<=':
            return _fees <= value
        else:
            return False