/**
 * This file is part of the Crypto Trader JavaScript starter bot
 *
 * Last update: February 27, 2018
 *
 * @author Niko van Meurs <niko@riddles.io>
 * @author Dino Hensen <dino@riddles.io>
 * @License MIT License (http://opensource.org/Licenses/MIT)
 */
const readline = require('readline');
const utils = require('./utils');
const Candle = require('./Candle');
const Chart = require('./Chart');
const BotStrategy = require('./BotStrategy');

module.exports = class Bot {
    constructor() {
        this.gameSettings = {
            timebank: null,
            time_per_move: null,
            player_names: null,
            your_bot: null,
            candle_interval: null,
            candle_format: null,
            candles_total: null,
            candles_given: null,
            initial_stack: null,
        };

        this.state = {
            date: null,
            charts: {},
            stacks: {},
        };

        this.strategy = new BotStrategy();
    }

    run() {
        this.io = readline.createInterface(process.stdin, process.stdout);
        this.io.on('line', this.handleLine.bind(this));
        this.io.on('close', this.handleIOClose.bind(this));
    }

    handleLine(data) {
        // stop if line doesn't contain anything
        if (data.length === 0) {
            return;
        }

        const lines = data.trim().split('\n');

        while (0 < lines.length) {
            const line = lines.shift().trim();
            const lineParts = line.split(' ');

            // stop if lineParts doesn't contain anything
            if (lineParts.length === 0) {
                return;
            }

            // get the input command and convert to camel case
            const command = utils.toCamelCase(lineParts.shift());

            // invoke command if function exists and pass the data along
            // then return response if exists
            if (this[command] instanceof Function) {
                const response = this[command](lineParts);

                if (response && 0 < response.length) {
                    process.stdout.write(response + '\n');
                }
            } else {
                process.stderr.write(
                    'Unable to execute command: ' + command + ', with data: ' + lineParts + '\n'
                );
            }
        }
    }

    handleIOClose() {
        process.exit(0);
    }

    /**
     * Writes a setting to the Bot.gameSettings object
     * @param {Array} data
     */
    settings(data) {
        const key = data[0];
        const value = data[1];

        // set key to value
        switch (key) {
            case 'candle_format':
                this.gameSettings.candle_format = value.split(',');
                break;
            case 'timebank':
            case 'time_per_move':
            case 'candle_interval':
            case 'candles_total':
            case 'candles_given':
            case 'initial_stack':
                this.gameSettings[key] = Number.parseInt(value);
                break;
            default:
                this.gameSettings[key] = value;
        }
    }

    /**
     * Called when the engine sends an `update` message.
     * This function either updates the game data (field or round) or
     * the player data.
     *
     * @param {Array} data
     */
    update(data) {
        const command = data.shift();

        if (command === 'game') {
            this.updateGame(data);
            return;
        }
    }

    /**
     * Updates the game state with data provided by the engine
     *
     * @param {Array} data
     */
    updateGame(data) {
        switch (data[0]) {
            case 'next_candles':
                this.updateChart(data[1]);
                break;
            case 'stacks':
                this.updateStacks(data[1]);
                break;
            default:
                console.error(`Cannot parse game data input with key ${data[0]}`);
        }
    }

    updateChart(data) {
        const chartStrings = data.split(';');
        let dateUpdated = false;

        for (const candleString of chartStrings) {
            let candle = new Candle(this.gameSettings.candle_format, candleString);
            if (!this.state.charts.hasOwnProperty(candle.pair)) {
                this.state.charts[candle.pair] = new Chart();
            }
            this.state.charts[candle.pair].addCandle(candle);

            if (!dateUpdated) {
                this.state.date = candle.date;
                dateUpdated = true;
            }
        }
    }

    updateStacks(data) {
        const stackStrings = data.split(',');
        for (const stackString of stackStrings) {
            const parts = stackString.split(':');
            if (!this.state.stacks.hasOwnProperty(parts[0])) {
                this.state.stacks[parts[0]] = {};
            }
            this.state.stacks[parts[0]] = Number.parseFloat(parts[1]);
        }
    }

    /**
     * This function is executed every time the game engine requests the bot
     * to make a move. It executes the strategy defined in the constructor and
     * returns the resulting move, which is sent to the engine by the Bot.run method.
     *
     * @param {Array} data
     * @returns {String | null}
     */
    action(data) {
        if (data[0] === 'order') {
            this.state.timebank = parseInt(data[1], 10);
            return this.strategy.execute(this.gameSettings, this.state);
        }
    }
};