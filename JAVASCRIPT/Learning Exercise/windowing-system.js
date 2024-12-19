// Solution for Windowing System

/**
 * Implement the classes etc. that are needed to solve the
 * exercise in this file. Do not forget to export the entities
 * you defined so they are available for the tests.
 */

export class Size {
  constructor(width = 80, height = 60) {
    this.width = width;
    this.height = height;
  }
  resize(newWidth, newHeight) {
    this.width = newWidth;
    this.height = newHeight;
  }
}

export class Position {
  constructor(x = 0, y = 0) {
    this.x = x;
    this.y = y;
  }
  move(newX, newY) {
    this.x = newX;
    this.y = newY;
  }
}

export class ProgramWindow {
  constructor() {
    this.screenSize = new Size(800, 600);
    this.size = new Size();
    this.position = new Position();
  }
  resize(newSize) {
    const maxWidth = this.screenSize.width - this.position.x,
      maxHeight = this.screenSize.height - this.position.y;
    this.size.width = Math.min(newSize.width, maxWidth);
    this.size.height = Math.min(newSize.height, maxHeight);
    this.size.width = Math.max(1, this.size.width);
    this.size.height = Math.max(1, this.size.height);
  }
  move(newPosition) {
    this.position.x = Math.min(
      newPosition.x,
      this.screenSize.width - this.size.width
    );
    this.position.y = Math.min(
      newPosition.y,
      this.screenSize.height - this.size.height
    );
    this.position.x = Math.max(0, this.position.x);
    this.position.y = Math.max(0, this.position.y);
  }
}

export function changeWindow(programWindow) {
  const newSize = new Size(400, 300),
    newPosition = new Position(100, 150);
  programWindow.resize(newSize);
  programWindow.move(newPosition);
  return programWindow;
}
