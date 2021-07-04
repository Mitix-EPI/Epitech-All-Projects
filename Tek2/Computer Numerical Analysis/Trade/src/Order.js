/**
 * This file is part of the Crypto Trader JavaScript starter bot
 *
 * Last update: February 27, 2018
 *
 * @author Dino Hensen <dino@riddles.io>
 * @License MIT License (http://opensource.org/Licenses/MIT)
 */
module.exports = class Order {
    constructor(type, pair, amount) {
        this.type = type;
        this.pair = pair;
        this.amount = amount;
    }

    toString() {
        return `${this.type} ${this.pair} ${this.amount}`;
    }
};
