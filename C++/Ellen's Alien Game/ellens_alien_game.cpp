namespace targets {
    class Alien {
    public:
        Alien(int x, int y) : x_coordinate(x), y_coordinate(y), health(3) {}

        int get_health() const {
            return health;
        }

        bool hit() {
            if (health > 0) {
                health--;
                return true;
            }
            return false;
        }

        bool is_alive() const {
            return health > 0;
        }

        bool teleport(int x_new, int y_new) {
            x_coordinate = x_new;
            y_coordinate = y_new;
            return true;
        }

        bool collision_detection(const Alien& other_alien) const {
            return x_coordinate == other_alien.x_coordinate && y_coordinate == other_alien.y_coordinate;
        }

        int x_coordinate, y_coordinate;

    private:
        int health;
    };
}  