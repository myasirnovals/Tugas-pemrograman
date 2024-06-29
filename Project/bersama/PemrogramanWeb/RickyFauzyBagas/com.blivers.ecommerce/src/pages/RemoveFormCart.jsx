// actions/cartActions.js
export const removeFromCart = (productId) => {
  return {
    type: 'REMOVE_FROM_CART',
    payload: productId,
  };
};
