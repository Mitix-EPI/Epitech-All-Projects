const Order = require('./Order');

function getBodyTop(candle) {
    if (candle.close > candle.open)
        return candle.close;
    return candle.open;
}

function getBodyBottom(candle) {
    if (candle.close > candle.open)
        return candle.open;
    return candle.close;
}

module.exports = class BuyStrat {

    constructor() {}

    /**
     * First winning strategy.
     * @param {Array<Candle>} Array of 5 Candles.
     * @returns {bool} Return boolean
    */
    isBullishHarami(candles) {
        let lastCandle = candles[4];
        let currentCandle = candles[5]

        let calc = (Math.abs(lastCandle.open - lastCandle.close)) / (Math.abs(lastCandle.low - lastCandle.high));

        if (lastCandle.open > lastCandle.close)
            if (currentCandle.open < currentCandle.close)
                if (lastCandle.close < currentCandle.open)
                    if (lastCandle.open > currentCandle.close)
                        if (calc > 0.6)
                            return true;
        return false;
    }

    /**
     * Second winning strategy.
     * @param {Array<Candle>} Array of 5 Candles.
     * @returns {bool} Return boolean
    */
     isBullishEngulfing(candles) {
        let lastCandle = candles[4];
        let currentCandle = candles[5]

        let calc = (Math.abs(lastCandle.open - lastCandle.close)) / (Math.abs(lastCandle.low - lastCandle.high));

        if (lastCandle.open > lastCandle.close)
            if (currentCandle.open < currentCandle.close)
                if (lastCandle.close > currentCandle.open)
                    if (lastCandle.open < currentCandle.close)
                        if (calc > 0.6)
                            return true;
        return false;
    }

    /**
     * Third winning strategy.
     * @param {Array<Candle>} Array of 5 Candles.
     * @returns {bool} Return boolean
    */
     isBullishDoji(candles) {
        let lastCandle = candles[4];
        let currentCandle = candles[5]

        let calc = (Math.abs(lastCandle.open - lastCandle.close)) / (Math.abs(lastCandle.low - lastCandle.high));

        if (lastCandle.open > lastCandle.close)
            if (lastCandle.low < currentCandle.low)
                if (currentCandle.high - currentCandle.close > 3 * Math.abs(currentCandle.open - currentCandle.close))
                    if (currentCandle.open - currentCandle.low < (currentCandle.high - currentCandle.close) / 3)
                        if (calc > 0.6)
                            return true;
        return false;
    }

    /**
     * Fourth winning strategy.
     * @param {Array<Candle>} Array of 5 Candles.
     * @returns {bool} Return boolean
    */
     isHammer(candles) {
        let lastCandle = candles[4];
        let currentCandle = candles[5]

        if (lastCandle.open > lastCandle.close)
            if (lastCandle.low < currentCandle.low)
                if (getBodyBottom(currentCandle) - currentCandle.low > 2 * Math.abs(currentCandle.open - currentCandle.close))
                    if (currentCandle.high - getBodyTop(currentCandle) < 0.3 * Math.abs(currentCandle.open - currentCandle.close))
                        return true;
        return false;
    }

    /**
     * Fifth winning strategy.
     * @param {Array<Candle>} Array of 5 Candles.
     * @returns {bool} Return boolean
    */
     isMorningstar(candles) {
        let lastCandle = candles[3];
        let previousCandle = candles[4];
        let currentCandle = candles[5]

        let firstCalc = (Math.abs(lastCandle.open - lastCandle.close)) / (Math.abs(lastCandle.low - lastCandle.high));
        let secondCalc = (Math.abs(previousCandle.open - previousCandle.close)) / (Math.abs(previousCandle.low - previousCandle.high));

        if (lastCandle.open > lastCandle.close)
            if (currentCandle.open < currentCandle.close)
                if (firstCalc > 0.6)
                    if (previousCandle.open < lastCandle.close)
                        if (currentCandle.open > previousCandle.close)
                            if (secondCalc < 0.3)
                                if (previousCandle.open - previousCandle.close < Math.abs(lastCandle.open - lastCandle.close))
                                    if (previousCandle.open - previousCandle.close < Math.abs(currentCandle.open - currentCandle.close))
                                        if (previousCandle.low < currentCandle.low)
                                            if (previousCandle.low < lastCandle.low)
                                                if (previousCandle.high < lastCandle.open)
                                                    if (previousCandle.high < currentCandle.close)
                                                        return true;
        return false;
    }

    /**
     * Sixth winning strategy.
     * @param {Array<Candle>} Array of 5 Candles.
     * @returns {bool} Return boolean
    */
    isGrowing(candles) {
        let oldOldOldCandle = candles[0];
        let oldOldCandle = candles[1];
        let oldCandle = candles[2];
        let lastCandle = candles[3];
        let previousCandle = candles[4];
        let currentCandle = candles[5]

        if (oldOldOldCandle.close < oldOldCandle.close)
            if (oldOldCandle.close < oldCandle.close)
                if (oldCandle.close < lastCandle.close)
                    if (lastCandle.close < previousCandle.close)
                        if (previousCandle.close < currentCandle.close)
                            if (currentCandle.open < currentCandle.close)
                                return true;
        return false;
    }

    shouldBuy1(candles) {
        let oldOldOldCandle = candles[0];
        let currentCandle = candles[5]
        if (currentCandle.close > oldOldOldCandle.close * 1.1)
            return true;
        return false;
    }

    shouldBuy2(candles) {
        let oldOldOldCandle = candles[1];
        let currentCandle = candles[5]
        if (currentCandle.close > oldOldOldCandle.close * 1.1)
            return true;
        return false;
    }

    shouldBuy3(candles) {
        let oldOldOldCandle = candles[2];
        let currentCandle = candles[5]
        if (currentCandle.close > oldOldOldCandle.close * 1.5)
            return true;
        return false;
    }
};
