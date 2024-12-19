// Solution for Poetry Club Door Policy

/**
 * Respond with the correct character, given the line of the
 * poem, if this were said at the front door.
 *
 * @param {string} line
 * @returns {string}
 */
export function frontDoorResponse(line) {
  for (let i = 0; i < line.length; i++) {
    if (line.charAt(i) !== " ") return line.charAt(i);
  }
}

/**
 * Format the password for the front-door, given the response
 * letters.
 *
 * @param {string} word the letters you responded with before
 * @returns {string} the front door password
 */
export function frontDoorPassword(word) {
  return word.charAt(0).toUpperCase() + word.slice(1).toLowerCase();
}

/**
 * Respond with the correct character, given the line of the
 * poem, if this were said at the back door.
 *
 * @param {string} line
 * @returns {string}
 */
export function backDoorResponse(line) {
  const cleanedLine = line.replace(/\s+$/, "");
  for (let i = cleanedLine.length - 1; i >= 0; i--) {
    if (line.charAt(i) !== " ") return cleanedLine.charAt(i);
  }
}

/**
 * Format the password for the back door, given the response
 * letters.
 *
 * @param {string} word the letters you responded with before
 * @returns {string} the back door password
 */
export function backDoorPassword(word) {
  return (
    word.charAt(0).toUpperCase() + word.slice(1).toLowerCase() + ", please"
  );
}
