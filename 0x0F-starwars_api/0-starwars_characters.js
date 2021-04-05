#!/usr/bin/node
// script that prints all characters of a Star Wars movie in order
const request = require('request');
const myArgs = process.argv.splice(2);
const URL = 'https://swapi-api.hbtn.io/api/films/' + myArgs[0];
function charactersFunc (character, i, stop) {
  if (i === stop) {
    return;
  }
  const movieCharacter = character[i];
  request(movieCharacter, function (err, response, body) {
    if (err) {
      console.log(err);
    } else {
      console.log(JSON.parse(body).name);
    }
  });
  i++;
  charactersFunc(character, i, stop);
}
request(URL, function (err, response, body) {
  if (err) {
    console.log(err);
  } else {
    const character = JSON.parse(body).characters;
    charactersFunc(character, 0, character.length);
  }
});
