// Solution for Resistor Color Duo

export const COLORS = [
  "black",
  "brown",
  "red",
  "orange",
  "yellow",
  "green",
  "blue",
  "violet",
  "grey",
  "white",
];

export const decodedValue = (colors) => {
  const firstColorValue = COLORS.indexOf(colors[0]),
    secondColorValue = COLORS.indexOf(colors[1]);
  return firstColorValue * 10 + secondColorValue;
};
