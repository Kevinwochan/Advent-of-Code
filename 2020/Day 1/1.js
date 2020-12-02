const { count } = require('console');
const { lookup } = require('dns');

fs = require('fs');

fs.readFile('input.txt', 'utf8', (err, data) => {
    let lookupTable = new Set(data.split('\n').map(line => Number(line)));
    lookupTable.forEach(num => {
        const counterPart = 2020 - num;
        if (lookupTable.has((counterPart))) {
            console.log(counterPart * num);
        }
    });
});
