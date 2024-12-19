// Solution for Pizza Order

/**
 * Determine the price of the pizza given the pizza and optional extras
 *
 * @param {Pizza} pizza name of the pizza to be made
 * @param {Extra[]} extras list of extras
 *
 * @returns {number} the price of the pizza
 */
export function pizzaPrice(pizza, ...extras) {
  const pizzaPrices = {
    Margherita: 7,
    Caprese: 9,
    Formaggio: 10,
  };
  let totalPrice = pizzaPrices[pizza] || 0;
  extras.forEach((extra) => {
    if (extra === "ExtraSauce") totalPrice += 1;
    else if (extra === "ExtraToppings") totalPrice += 2;
  });
  return totalPrice;
}

/**
 * Calculate the price of the total order, given individual orders
 *
 * (HINT: For this exercise, you can take a look at the supplied "global.d.ts" file
 * for a more info about the type definitions used)
 *
 * @param {PizzaOrder[]} pizzaOrders a list of pizza orders
 * @returns {number} the price of the total order
 */
export function orderPrice(pizzaOrders) {
  return pizzaOrders.reduce((total, order) => {
    return total + pizzaPrice(order.pizza, ...order.extras);
  }, 0);
}
