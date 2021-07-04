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

function getShadowTop(candle) {
    return Math.abs(candle.high - getBodyTop(candle));
}

function getShadowBottom(candle) {
    return Math.abs(candle.low - getBodyBottom(candle));
}

module.exports = class SellStrat {
    constructor() {}

    /**
     * First sell strategy.
     * @param {Array<Candle>} Array of 5 Candles.
     * @returns {bool} Return boolean
    */
    isBearishHarami(candles) {
        let lastCandle = candles[4];
        let currentCandle = candles[5]

        let calc = (Math.abs(lastCandle.open - lastCandle.close)) / (Math.abs(lastCandle.high - lastCandle.low));

        if (lastCandle.open < lastCandle.close)
            if (currentCandle.open > currentCandle.close)
                if (lastCandle.close > currentCandle.open)
                    if (lastCandle.open < currentCandle.close)
                        if (calc > 0.6)
                            return true;
        return false;
    }

    /**
     * Second sell strategy.
     * @param {Array<Candle>} Array of 5 Candles.
     * @returns {bool} Return boolean
    */
    isHangingMan(candles) {
        let lastCandle = candles[4];
        let currentCandle = candles[5]

        let calc = (Math.abs(lastCandle.open - lastCandle.close)) / (Math.abs(lastCandle.low - lastCandle.high));

        if (lastCandle.open < lastCandle.close)
            if (calc > 0.6)
                if (currentCandle.high > lastCandle.high)
                    if (getShadowBottom(currentCandle) > 2 * (Math.abs(lastCandle.open - lastCandle.close)))
                        if (getShadowTop(currentCandle) > 0.3 * (Math.abs(lastCandle.open - lastCandle.close)))
                            return true;
        return false;
    }

    /**
     * Third sell strategy.
     * @param {Array<Candle>} Array of 5 Candles.
     * @returns {bool} Return boolean
    */
     isBearishEngulfing(candles) {
        let lastCandle = candles[4];
        let currentCandle = candles[5]

        let calc = (Math.abs(currentCandle.open - currentCandle.close)) / (Math.abs(currentCandle.high - currentCandle.low));

        if (lastCandle.open < lastCandle.close)
            if (currentCandle.open > currentCandle.close)
                if (getBodyBottom(currentCandle) < getBodyBottom(lastCandle))
                    if (getBodyTop(currentCandle) < getBodyTop(lastCandle))
                        if (calc > 0.6)
                            return true;
        return false;
    }

    /**
     * Fourth sell strategy.
     * @param {Array<Candle>} Array of 5 Candles.
     * @returns {bool} Return boolean
    */
     isEveningStar(candles) {
        let lastCandle = candles[3];
        let previousCandle = candles[4];
        let currentCandle = candles[5]

        let firstCalc = (Math.abs(lastCandle.open - lastCandle.close)) / (Math.abs(lastCandle.low - lastCandle.high));
        let secondCalc = (Math.abs(previousCandle.open - previousCandle.close)) / (Math.abs(previousCandle.low - previousCandle.high));

        if (lastCandle.open < lastCandle.close)
            if (currentCandle.open > currentCandle.close)
                if (firstCalc > 0.6)
                    if (previousCandle.open > lastCandle.close)
                        if (currentCandle.open < previousCandle.close)
                            if (secondCalc < 0.3)
                                if (previousCandle.open - previousCandle.close < Math.abs(lastCandle.open - lastCandle.close))
                                    if (previousCandle.open - previousCandle.close < Math.abs(currentCandle.open - currentCandle.close))
                                        if (previousCandle.high > currentCandle.high)
                                            if (previousCandle.high > lastCandle.high)
                                                if (previousCandle.low > lastCandle.open)
                                                    if (previousCandle.low > currentCandle.close)
                                                        return true;
        return false;
    }

    /**
     * Fifth sell strategy.
     * @param {Array<Candle>} Array of 5 Candles.
     * @returns {bool} Return boolean
    */
    isGravestoneDoji(candles) {
        let lastCandle = candles[4];
        let currentCandle = candles[5]

        let calc = (Math.abs(currentCandle.open - currentCandle.close)) / (Math.abs(currentCandle.low - currentCandle.high));

        if (lastCandle.open < lastCandle.close)
            if (calc > 0.6)
                if (currentCandle.high > lastCandle.high)
                    if (currentCandle.high - currentCandle.close > 3 * Math.abs(currentCandle.open - currentCandle.close))
                        if (currentCandle.open - currentCandle.low < (currentCandle.high - currentCandle.close) / 3)
                            return true;
        return false;
    }

    /**
     * Sixth sell strategy.
     * @param {Array<Candle>} Array of 5 Candles.
     * @returns {bool} Return boolean
    */
    isFalling(candles) {
        let oldOldOldCandle = candles[0];
        let oldOldCandle = candles[1];
        let oldCandle = candles[2];
        let lastCandle = candles[3];
        let previousCandle = candles[4];
        let currentCandle = candles[5]

                    if (lastCandle.close > previousCandle.close)
                        if (previousCandle.close > currentCandle.close)
                            if (currentCandle.open > currentCandle.close)
                                return true;
        return false;
    }

    shouldSell1(candles) {
        let oldOldOldCandle = candles[0];
        let currentCandle = candles[5]
        if (currentCandle.close * 1.1 < oldOldOldCandle.close)
            return true;
        return false;
    }

    shouldSell2(candles) {
        let oldOldOldCandle = candles[1];
        let currentCandle = candles[5]
        if (currentCandle.close * 1.2 < oldOldOldCandle.close)
            return true;
        return false;
    }

    shouldSell3(candles) {
        let oldOldOldCandle = candles[2];
        let currentCandle = candles[5]
        if (currentCandle.close * 1.3 < oldOldOldCandle.close)
            return true;
        return false;
    }
}