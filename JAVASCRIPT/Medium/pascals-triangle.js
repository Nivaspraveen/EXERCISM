// Solution for Pascal's Triangle

export const rows = (n) => {
  if (n <= 0) return [];
  const triangle = [[1]];
  for (let i = 1; i < n; i++) {
    const prevRow = triangle[i - 1],
      currRow = [1];
    for (let j = 1; j < prevRow.length; j++)
      currRow.push(prevRow[j - 1] + prevRow[j]);
    currRow.push(1);
    triangle.push(currRow);
  }
  return triangle;
};
