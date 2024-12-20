// Solution for Pangram

export const isPangram = (s) => {
  const alphabet = "abcdefghijklmnopqrstuvwxyz";
  const normalizedS = s.toLowerCase();
  for (let letter of alphabet) {
    if (!normalizedS.includes(letter)) return false;
  }
  return true;
};
