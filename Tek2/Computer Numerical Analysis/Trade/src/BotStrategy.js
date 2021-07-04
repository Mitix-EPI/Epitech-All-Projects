// /home/alexandre/Downloads/training_set.csv

/**
 *
 * Last update: April 19, 2021
 *
 * @author Juan Alexandre <alexandre.juan@epitech.eu>
 * @author Deurveilher Jean Louis <jean-louis.deurveilher@epitech.eu>
 */
const { default: Candle } = require('./Candle');
const Order = require('./Order');
const BuyStrat = require("./BuyStrategy");
const SellStrat = require("./SellStrategy");


let firstTime = true;
let count = 0;
let buyStrat = new BuyStrat();
let sellStrat = new SellStrat();

module.exports = class BotStrategy {
    constructor() {
        let dollars = 0;
        let eth = 0;
        let btc = 0;
        let state;
        let gameSettings;
        let orders = [];
        let score = 0;
    }

    convertToCommand(orders) {
        if (orders.length < 1)
            return 'pass';
        let result = '';

        for (let order of orders) {
            result += order;
            result += '; ';
        }
        console.error('ORDER : ', result, '\n');
        return result;
    }

    /**
     * Update the current wallet.
     * @param {string} pair Pair (example: "USDT_ETH")
     * @param {number} amount The amount you have to pay the pair.
     */
    updateAmount(pair, amount) {
        if (pair == 'USDT_ETH') {
            this.eth += amount / this.state.charts['USDT_ETH'].getCandleAt(this.state.date).close;
            this.dollars -= amount;
        } else if (pair == 'USDT_BTC') {
            this.btc += amount / this.state.charts['USDT_BTC'].getCandleAt(this.state.date).close;
            this.dollars -= amount;
        } else if (pair == 'BTC_ETH') {
            this.eth += amount / this.state.charts['BTC_ETH'].getCandleAt(this.state.date).close;
            this.btc -= amount;
        }
        // console.error("\nUPDATE AMOUNT");
        // console.error("dollars : ", this.dollars);
        // console.error("btc : ", this.btc);
        // console.error("eth : ", this.eth);
        // console.error("END UPDATE AMOUNT\n");
    }

    /**
     * Sell or Buy on the market.
     * @param {string} type Must be 'sell' or 'buy'
     * @param {string} pair Pair (example: "USDT_ETH")
     * @param {number} amount The amount you have to pay the pair.
     */
    order(type, pair, amount) {
        if (amount <= 0)
            return;
        this.updateAmount(pair, amount);
        if (type == 'buy') {
            amount /= this.state.charts[pair].getCandleAt(this.state.date).close;
        }
        this.orders.push(new Order(type, pair, amount).toString());
    }

    /**
     * Display all the current currencies in the wallet.
     */
    displayWallet() {
        console.error("------------------------");
        console.error("WALLET : ");
        console.error("USDT : ", this.dollars);
        console.error("BTC : ", this.btc);
        console.error("ETH : ", this.eth);
        console.error("------------------------");
    }

    /**
     * Get the 5 latests candles + the actual. [0] is the latest, [4] is the previous one.
     * @param {string} pair Pair (example: "USDT_ETH")
     * @returns {Array<Candle>} Return an array of 5 Candles.
     */
    getFiveLastCandles(pair) {
        let lastDate = this.state.date.getTime();
        let oldDate = lastDate - ((this.gameSettings.candle_interval * 1000) * 5);
        let result = [];

        for (let i = oldDate; i < lastDate; i += this.gameSettings.candle_interval * 1000) {
            result.push(this.state.charts[pair].candles[i]);
        }
        result.push(this.state.charts[pair].candles[lastDate]);
        return result;
    }

    getBodyDiff(candle) {
        return candle.close - candle.open;
    }

    getBodyValue(candle) {
        return (candle.close + candle.open) / 2;
    }

    getAverageBody(candles) {
        let result = 0;
        let i = 0;

        for (let candle of candles) {
            result += this.getBodyValue(candle);
            i++;
        }
        return result / i;
    }

    /**
     * Calc the percentage of the amount
     * @param {number} amount Amount
     * @param {*} percent Percentage (%)
     * @returns
     */
    getPercent(amount, percent) {
        if (percent > 100)
            percent = 100
        if (percent <= 0)
            percent = 1
        return (amount * percent) / 100
    }

    isLowGreaterThanHigh(low, high, open, close) {
        if ((close - low) > (high - open))
            return true;
        return false;
    }

    execute(gameSettings, state) {
        this.state = state;
        this.orders = [];
        this.gameSettings = gameSettings;
        this.dollars = state.stacks['USDT'];
        this.eth = state.stacks['ETH'];
        this.btc = state.stacks['BTC'];
        this.score = 0;

        this.getFiveLastCandles('USDT_ETH');
        this.displayWallet();

        let candlesEth = this.getFiveLastCandles('USDT_ETH');
        let candlesBtc = this.getFiveLastCandles('USDT_BTC');

        if (firstTime) {
            this.order('buy', 'USDT_ETH', this.getPercent(this.dollars, 60));
            this.order('buy', 'USDT_BTC', this.getPercent(this.dollars, 50));
            firstTime = false;
            return this.convertToCommand(this.orders);
        }

        if (buyStrat.shouldBuy1(candlesEth)) {
            console.error("BUY STRAT\tshouldBuy1");
            this.score += 6;
        }
        if (buyStrat.shouldBuy2(candlesEth)) {
            console.error("BUY STRAT\tshouldBuy2");
            this.score += 3;
        }
        if (buyStrat.shouldBuy3(candlesEth)) {
            console.error("BUY STRAT\tshouldBuy3");
            this.score += 2;
        }
        if (buyStrat.isGrowing(candlesEth)) {
            console.error("BUY STRAT\tisGrowing");
            this.score += 3;
        }

        if (sellStrat.isFalling(candlesEth)) {
            console.error("SELL STRAT\tisFalling")
            this.score -= 3;
        }

        console.error("SCORE : ", this.score);
        if (this.score > 0) {
            if (this.score > 10)
                this.score = 10;
            this.order('buy', 'USDT_ETH', this.getPercent(this.dollars, this.score * 9));
        } else if (this.score < 0) {
            if (this.score < -10)
                this.score = -10;
            if (this.eth > 0.0001)
                this.order('sell', 'USDT_ETH', this.getPercent(this.eth, Math.abs(this.score) * 9));
        }

        this.score = 0;
        if (buyStrat.shouldBuy1(candlesBtc)) {
            console.error("BUY STRAT\tshouldBuy1");
            this.score += 6;
        }
        if (buyStrat.shouldBuy2(candlesBtc)) {
            console.error("BUY STRAT\tshouldBuy2");
            this.score += 3;
        }
        if (buyStrat.shouldBuy3(candlesBtc)) {
            console.error("BUY STRAT\tshouldBuy3");
            this.score += 2;
        }
        if (buyStrat.isGrowing(candlesBtc)) {
            console.error("BUY STRAT\tisGrowing");
            this.score += 3;
        }

        if (sellStrat.isFalling(candlesBtc)) {
            console.error("SELL STRAT\tisFalling")
            this.score -= 6;
        }
        console.error("SCORE : ", this.score);
        if (this.score > 0) {
            if (this.score > 10)
                this.score = 10;
            if (this.dollars > 1)
                this.order('buy', 'USDT_BTC', this.getPercent(this.dollars, this.score * 9));
        } else if (this.score < 0) {
            if (this.score < -10)
                this.score = -10;
            if (this.btc > 0.0001)
                this.order('sell', 'USDT_BTC', this.getPercent(this.btc, Math.abs(this.score) * 9));
        }
        return this.convertToCommand(this.orders);
    }
};