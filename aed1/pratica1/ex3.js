let args = process.argv.slice(2);
args = args.map(arg => Number(arg))
console.log('myArgs: ', args);
let media = 0
for (let i = 0; i < args.length; i++) media = media + args[i]
media = media / args.length
let count = 0
for (let i = 0; i < args.length; i++) {
  if (args[i] > media) count++
}
console.log("Media: " + media, "\nQuantidade de números que excedem a média " + count);