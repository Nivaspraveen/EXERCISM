// Solution for Space Age

export const age = (planet, seconds) => {
  const earthYearInSecs = 31557600;
  const orbitTime = {
    Mercury: 0.2408467,
    Venus: 0.61519726,
    Earth: 1.0,
    Mars: 1.8808158,
    Jupiter: 11.862615,
    Saturn: 29.447498,
    Uranus: 84.016846,
    Neptune: 164.79132,
  };
  const properTime =
    planet.charAt(0).toUpperCase() + planet.slice(1).toLowerCase();
  const time = orbitTime[properTime];
  if (time === undefined) throw new Error(`Unknown planet: ${planet}`);
  const planetAge = seconds / (earthYearInSecs * time);
  return parseFloat(planetAge.toFixed(2));
};
