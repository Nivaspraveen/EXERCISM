// Solution for Book Store

export const cost = (books) => {
  const discount = { 1: 0.0, 2: 0.05, 3: 0.1, 4: 0.2, 5: 0.25 };

  const groupPrice = (groupSize) => {
    const basePrice = 8 * groupSize * 100,
      discountAmt = basePrice * discount[groupSize];
    return basePrice - discountAmt;
  };

  const bookCounts = {};
  books.forEach((book) => {
    bookCounts[book] = (bookCounts[book] || 0) + 1;
  });

  const bookCountArray = Object.values(bookCounts),
    dp = {};
  const findMinCost = (counts) => {
    if (counts.length === 0) return 0;
    counts.sort((a, b) => b - a);
    const key = counts.join(",");
    if (dp[key] !== undefined) return dp[key];
    let minCost = Infinity;

    const n = counts.length;
    for (let i = 1; i <= 5; i++) {
      const newCounts = [...counts];
      let canFormGroup = true,
        numBooks = 0;

      for (let j = 0; j < n && numBooks < i; j++) {
        if (newCounts[j] > 0) {
          newCounts[j]--;
          numBooks++;
        } else {
          canFormGroup = false;
          break;
        }
      }

      if (canFormGroup) {
        const remainingCost = findMinCost(newCounts.filter((x) => x > 0));
        minCost = Math.min(minCost, groupPrice(i) + remainingCost);
      }
    }
    dp[key] = minCost;
    return dp[key];
  };
  return findMinCost(bookCountArray);
};
