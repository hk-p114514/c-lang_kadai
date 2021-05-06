const rand = (min, max) => {
  return Math.floor(Math.random() * (max - min + 1)) + min;
};

for (let i = 0; i < 100; i++) {
  console.log(rand(rand(0, 100), rand(0, 100)));
}
