//index.js
const testAddon = require("./build/Release/hello.node");

console.log("addon", testAddon);
console.log(testAddon.hello());

module.exports = testAddon;
