// Solution for Bob

export const hey = (message) => {
  const trimmedMsg = message.trim();
  if (trimmedMsg === "") return "Fine. Be that way!";
  const isYelling =
      trimmedMsg === trimmedMsg.toUpperCase() && /[A-Z]/.test(trimmedMsg),
    isQuestion = trimmedMsg.endsWith("?");
  if (isYelling && isQuestion) return "Calm down, I know what I'm doing!";
  else if (isYelling) return "Whoa, chill out!";
  else if (isQuestion) return "Sure.";
  else return "Whatever.";
};
