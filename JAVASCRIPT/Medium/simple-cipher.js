// Solution for Simple Cipher

export class Cipher {
  constructor(key) {
    if (key === undefined) {
      this._key = Array.from({ length: 100 }, () =>
        String.fromCharCode(97 + Math.floor(Math.random() * 26))
      ).join("");
    } else if (!/^[a-z]+$/.test(key))
      throw new Error("Invalid key: Key must contain only lowercase letters");
    else this._key = key;
  }

  cipher(input, mode) {
    const shiftFactor = mode === "encode" ? 1 : -1,
      keyLength = this._key.length;
    return Array.from(input)
      .map((char, index) => {
        const keyChar = this._key[index % keyLength],
          shift = keyChar.charCodeAt(0) - 97,
          originalCode = char.charCodeAt(0) - 97,
          newCode = (originalCode + shiftFactor * shift + 26) % 26;
        return String.fromCharCode(newCode + 97);
      })
      .join("");
  }

  encode(plainText) {
    return this.cipher(plainText, "encode");
  }

  decode(plainText) {
    return this.cipher(plainText, "decode");
  }

  get key() {
    return this._key;
  }
}
