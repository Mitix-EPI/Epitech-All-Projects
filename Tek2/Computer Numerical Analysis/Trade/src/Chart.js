/**
 * This file is part of the Crypto Trader JavaScript starter bot
 *
 * Last update: February 27, 2018
 *
 * @author Dino Hensen <dino@riddles.io>
 * @License MIT License (http://opensource.org/Licenses/MIT)
 */
module.exports = class Chart {
    constructor() {
        this.candles = {};
    }

    addCandle(candle) {
        this.candles[candle.date.getTime()] = candle;
    }

    getCandleAt(date) {
        return this.candles[date.getTime()];
    }
};
