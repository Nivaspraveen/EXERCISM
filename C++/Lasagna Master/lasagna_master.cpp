#include "lasagna_master.h"
#include <vector> 
#include <string>

namespace lasagna_master {
    int preparationTime(const std::vector<std::string>& layers, int avgTimePerLayer) { 
        return layers.size() * avgTimePerLayer;
    }

    amount quantities(const std::vector<std::string>& layers) { 
        amount result{0, 0.0}; 
        for (const auto& layer : layers) { 
            if (layer == "noodles") result.noodles += 50;
            else if (layer == "sauce") result.sauce += 0.2;
        } 
        return result;
    }

    void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList) { 
        if (!friendsList.empty()) myList.back() = friendsList.back(); 
    }

    std::vector<double> scaleRecipe(const std::vector<double>& quantities, int portions) { 
        std::vector<double> scaledQuantities; 
        for (const auto& quantity : quantities) 
            scaledQuantities.push_back(quantity * (portions / 2.0)); 
        return scaledQuantities; 
    } 
    
    void addSecretIngredient(std::vector<std::string>& myList, const std::string& secretIngredient) { 
        myList.back() = secretIngredient;
    }
}  

