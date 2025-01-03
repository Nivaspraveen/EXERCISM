// Solution for RNA Transcription

export const toRna = (dna) => {
  const complement = { G: "C", C: "G", T: "A", A: "U" };
  return dna
    .split("")
    .map((nuc) => complement[nuc])
    .join("");
};
