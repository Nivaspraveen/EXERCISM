#include <iostream>

namespace hellmath {
    enum class AccountStatus {
        troll, 
        guest, 
        user, 
        mod,
    };

    enum class Action {
        read,
        write, 
        remove
    };

    bool display_post(AccountStatus poster, AccountStatus viewer) {
        if (poster == AccountStatus::troll && viewer != AccountStatus::troll) return false;
        return true;
    }

    bool permission_check(Action action, AccountStatus account) {
        switch (action) {
            case Action::read: return true;
            case Action::write: return account == AccountStatus::user || account == AccountStatus::troll || account == AccountStatus::mod;
            case Action::remove: return account == AccountStatus::mod;
        }
        return false;
    }

    bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
        if (player1 == AccountStatus::guest || player2 == AccountStatus::guest) return false;
        if (player1 == AccountStatus::troll && player2 == AccountStatus::troll) return true;
        if (player1 == AccountStatus::troll || player2 == AccountStatus::troll) return false;
        return true;
    }

    bool has_priority(AccountStatus account1, AccountStatus account2) {
        if (account1 == AccountStatus::mod && account2 != AccountStatus::mod) return true;
        if (account1 == AccountStatus::user) {
            if (account2 == AccountStatus::guest || account2 == AccountStatus::troll) return true;
            return false;
        }
        if (account1 == AccountStatus::guest && account2 == AccountStatus::troll) return true;
        return false;
    }
}  