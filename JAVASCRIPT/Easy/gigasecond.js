// Solution for Gigasecond

export const gigasecond = (inputDate) => {
  const gigaSecond = 1_000_000_000,
    gigaSecondDate = new Date(inputDate.getTime() + gigaSecond * 1000);
  return gigaSecondDate;
};
