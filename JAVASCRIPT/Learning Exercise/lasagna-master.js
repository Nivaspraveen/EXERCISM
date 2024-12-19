// Solution for Lasagna Master

/**
 * Returns the status of the lasagna based on the remaining time.
 *
 * @param {number} [remainingTime] The remaining cooking time in minutes
 * @returns {string} The status message
 */

export function cookingStatus(remainingTime) {
  if (remainingTime === undefined) return "You forgot to set the timer.";
  else if (remainingTime === 0) return "Lasagna is done.";
  else return "Not done, please wait.";
}

/**
 * Returns the estimated preparation time based on the layers and average time per layer.
 *
 * @param {Array<string>} layers The list of layers in the lasagna
 * @param {number} [avgTimePerLayer=2] The average preparation time per layer in minutes
 * @returns {number} The total estimated preparation time
 */

export function preparationTime(layers, avgTimePerLayer = 2) {
  return layers.length * avgTimePerLayer;
}

/**
 * Returns an object with the quantities of noodles and sauce needed for the lasagna.
 *
 * @param {Array<string>} layers The list of layers in the lasagna
 * @returns {{noodles: number, sauce: number}} The quantities of noodles and sauce
 */

export function quantities(layers) {
  let noodles = 0,
    sauce = 0;
  layers.forEach((layer) => {
    if (layer === "noodles") noodles += 50;
    else if (layer === "sauce") sauce += 0.2;
  });
  return { noodles, sauce };
}

/**
 * Adds the last ingredient from the friend's list to your recipe list.
 * Modifies your recipe list directly.
 *
 * @param {Array<string>} friendsList The friend's ingredient list
 * @param {Array<string>} myList The recipe ingredient list to be modified
 */

export function addSecretIngredient(friendList, myList) {
  myList.push(friendList[friendList.length - 1]);
}

/**
 * Scales the recipe for the desired number of portions.
 * Returns a new recipe object without modifying the original.
 *
 * @param {Object} recipe The recipe object for 2 portions
 * @param {number} portions The number of portions to scale for
 * @returns {Object} The scaled recipe object
 */

export function scaleRecipe(recipe, portions) {
  const scaleRecipe = {};
  for (let ingridient in recipe)
    scaleRecipe[ingridient] = recipe[ingridient] * (portions / 2);
  return scaleRecipe;
}
