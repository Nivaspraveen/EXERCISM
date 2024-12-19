// Solution for Mixed Juices

/**
 * Determines how long it takes to prepare a certain juice.
 *
 * @param {string} name
 * @returns {number} time in minutes
 */
export function timeToMixJuice(name) {
  const prepTime = {
    "Pure Strawberry Joy": 0.5,
    "Energizer": 1.5,
    "Green Garden": 1.5,
    "Tropical Island": 3,
    "All or Nothing": 5,
  };
  return Object.keys(prepTime).includes(name) ? prepTime[name] : 2.5;
}

/**
 * Calculates the number of limes that need to be cut
 * to reach a certain supply.
 *
 * @param {number} wedgesNeeded
 * @param {string[]} limes
 * @returns {number} number of limes cut
 */
export function limesToCut(wedgesNeeded, limes) {
  const wedges = {
    small: 6,
    medium: 8,
    large: 10,
  };
  let limesCut = 0,
    i = 0;
  while (limesCut < wedgesNeeded) {
    limes[i] ? ((limesCut += wedges[limes[i]]), i++) : i;
    if (!limes[i]) return i;
  }
  return i;
}

/**
 * Determines which juices still need to be prepared after the end of the shift.
 *
 * @param {number} timeLeft
 * @param {string[]} orders
 * @returns {string[]} remaining orders after the time is up
 */
export function remainingOrders(timeLeft, orders) {
  while (timeLeft > 0) {
    timeLeft -= timeToMixJuice(orders[0]);
    orders.shift();
  }
  return orders;
}
