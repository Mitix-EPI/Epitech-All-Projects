/**
 * This file is part of the Crypto Trader JavaScript starter bot
 *
 * Last update: February 27, 2018
 *
 * @author Dino Hensen <dino@riddles.io>
 * @License MIT License (http://opensource.org/Licenses/MIT)
 */
module.exports = class Candle {
    constructor(format, input) {
        const values = input.split(',');
        for (let i = 0; i < format.length; i++) {
            const key = format[i];
            const value = values[i];
            switch (key) {
                case 'pair':
                    this.pair = value;
                    break;
                case 'date':
                    // multiply by 1000 because Date needs milliseconds, seconds given
                    this.date = new Date(Number.parseInt(value) * 1000);
                    break;
                case 'high':
                case 'low':
                case 'open':
                case 'close':
                case 'volume':
                    this[key] = Number.parseFloat(value);
                    break;
            }
        }
    }
};
