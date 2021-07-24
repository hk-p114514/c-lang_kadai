"use strict";

const rand = (min, max) => {
  return Math.floor(Math.random() * (max - min + 1));
};

const students = [
  "Adrian Cashmore 63 68 98",
  "Caleb Ralph 67 98 56",
  "Greg Smith 100 57 100",
  "Apisai Naevo 52 54 47",
  "Michael Collins 57 84 59",
  "Mark Robinson 58 55 56",
  "Jason Barrell 54 28 58",
  "Glen Osborne 87 47 58",
  "Jona Lomu 74 57 57",
  "Bklair Larsen 41 15 56",
  "Leo Lafaialii 58 55 65",
  "Mark Carter 87 91 54",
  "Eroni Clarke 75 75 68",
  "Craig Dowd 57 74 68",
  "Ian Foster 85 84 48",
  "Justin Collins 14 58 52",
  "Nick Holten 84 84 91",
  "Charles Riechelmann 48 65 47",
  "Ian Jones 74 84 87",
  "Joeli Vidiri 55 15 45",
  "Deon Muir 68 75 58",
  "Frank Bunce 73 84 65",
  "Glen Marsh 56 57 47",
  "BrettMc Cormack 98 95 100",
  "Bruce Reihana 52 58 58",
  "Erro Brain 62 84 54",
  "Jason Hammond 85 54 58",
  "Leon Macdonald 87 97 84",
  "Matt Cooper 55 56 57",
  "Michael Jones 74 87 69",
  "Andrew Blowers 67 74 54",
  "Aaon Hopa 54 55 49",
  "Janson Spice 98 100 95",
  "Lee Lidgard 51 54 25",
  "Andrew Roose 67 74 57",
  "Lee Stensness 85 98 91",
  "Dylan Mike 69 85 95",
  "Brian Lima 85 76 47",
  "Craig Innes 55 41 54",
  "Carlos Spencer 0 0 0",
  "Mark Cooksley 100 100 100",
];

for (let i = 0; i < 59; i++) {
  console.log(`${rand(59, 100)} ${students[rand(0, students.length - 1)]}`);
}
