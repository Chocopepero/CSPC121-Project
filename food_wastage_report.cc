// Samuel Kim
// CPSC 121L - 02
// 2023-11-09
// samkunkim@csu.fullerton.edu
// @ChocoPepero

#include "food_wastage_report.h"

#include <iomanip>
#include <map>
#include <vector>

int CalculateMax(const std::vector<int> &num) {
  // Small function to calculate max int from vector
  int max{0};
  for (int i : num) {
    if (i > max) {
      max = i;
    }
  }
  return max;
}

void FoodWastageReport::GenerateCommonWasteFood(
    const std::vector<FoodWastageRecord> &reported_food_list) {
  // Create an empty map and count how many times a food is recorded.
  // Loop through parameter vector, every time food is recorded:
  // Check if food is in map, if so add one occurence. Else add key/value.
  std::map<std::string, int> food_occurances{};
  for (FoodWastageRecord food_report : reported_food_list) {
    std::string food_name = food_report.GetFoodName();
    if (food_occurances.count(food_name) == 0) {
      food_occurances.insert({food_name, 1});
    } else {
      food_occurances.at(food_name)++;
    }
  }
  // Iterate through map and keep track of highest occurance.
  int highest_occurance{0};
  for (std::pair<std::string, int> occurances : food_occurances) {
    if (occurances.second > highest_occurance) {
      highest_occurance = occurances.second;
    }
  }
  // Go back through map and add any key with value == highest occurance and add
  // that key to vector.
  // NOTE: Extremely inefficient. High time complexity. Consider better
  // strategy.
  // Ask professors about map.upperbound()?
  // Create a new vector then make member variable = to new vector.
  std::vector<std::string> common_waste_new_report{};
  for (std::pair<std::string, int> occurances : food_occurances) {
    if (occurances.second == highest_occurance) {
      common_waste_new_report.push_back(occurances.first);
    }
  }
  common_waste_foods_ = common_waste_new_report;
}

void FoodWastageReport::GenerateCommonWasteMeals(
    const std::vector<FoodWastageRecord> &reported_food) {
  // Similar to previous function but only has 3 fixed options.
  // Iterate through vector, keep track of meals wasted via 3 ints.
  // Compare 3 ints to one another, add correlating meals to vector.
  int breakfast{0};
  int lunch{0};
  int dinner{0};
  for (FoodWastageRecord food_record : reported_food) {
    if (food_record.GetMeal() == "Breakfast") {
      breakfast++;
    }
    if (food_record.GetMeal() == "Lunch") {
      lunch++;
    }
    if (food_record.GetMeal() == "Dinner") {
      dinner++;
    }
  }
  std::vector<int> meal_occurance{breakfast, lunch, dinner};
  int largest = CalculateMax(meal_occurance);
  std::vector<std::string> waste_meal_report{};
  if (breakfast == largest) {
    waste_meal_report.push_back("Breakfast");
  }
  if (lunch == largest) {
    waste_meal_report.push_back("Lunch");
  }
  if (dinner == largest) {
    waste_meal_report.push_back("Dinner");
  }
  common_waste_meals_ = waste_meal_report;
}

void FoodWastageReport::CalculateCost(
    const std::vector<FoodWastageRecord> &reported_food_list) {
  double total_cost{0.0};
  for (FoodWastageRecord wasted_food : reported_food_list) {
    total_cost += wasted_food.GetCost();
  }
  total_cost_ = total_cost;
}

void FoodWastageReport::GenerateCommonReason(
    const std::vector<FoodWastageRecord> &reported_food_list) {
  // Similar to generate meal function but with 4 potential inputs.
  // Take same approach as inputs are finite.
  int leftover{0};
  int tastes_bad{0};
  int expired{0};
  int other{0};
  for (FoodWastageRecord food_record : reported_food_list) {
    if (food_record.GetWasteReason() == "Too much left overs") {
      leftover++;
    }
    if (food_record.GetWasteReason() == "Tastes bad") {
      tastes_bad++;
    }
    if (food_record.GetWasteReason() == "Expired") {
      expired++;
    }
    if (food_record.GetWasteReason() == "Other") {
      other++;
    }
  }
  std::vector<int> waste_occurance{leftover, tastes_bad, expired, other};
  int largest = CalculateMax(waste_occurance);
  std::vector<std::string> waste_reason_report{};
  if (leftover == largest) {
    waste_reason_report.push_back("Too much left overs");
  }
  if (tastes_bad == largest) {
    waste_reason_report.push_back("Tastes bad");
  }
  if (expired == largest) {
    waste_reason_report.push_back("Expired");
  }
  if (other == largest) {
    waste_reason_report.push_back("Other");
  }
  common_reason_ = waste_reason_report;
}

void FoodWastageReport::GenerateCommonMechOfDisposal(
    const std::vector<FoodWastageRecord> &reported_food_list) {
  // Same logic as generate meal and generate reason functions.
  // 6 fixed inputs
  // Sink Trash Feed to pet Compost Donation Other
  int sink{0};
  int trash{0};
  int feed_to_pet{0};
  int compost{0};
  int donation{0};
  int other{0};
  for (FoodWastageRecord food_record : reported_food_list) {
    if (food_record.GetDisposalMethod() == "Sink") {
      sink++;
    }
    if (food_record.GetDisposalMethod() == "Trash") {
      trash++;
    }
    if (food_record.GetDisposalMethod() == "Feed to pet") {
      feed_to_pet++;
    }
    if (food_record.GetDisposalMethod() == "Compost") {
      compost++;
    }
    if (food_record.GetDisposalMethod() == "Donation") {
      donation++;
    }
    if (food_record.GetDisposalMethod() == "Other") {
      other++;
    }
  }
  std::vector<int> waste_occurance{sink,    trash,    feed_to_pet,
                                   compost, donation, other};
  int largest = CalculateMax(waste_occurance);
  std::vector<std::string> waste_method_report{};
  if (sink == largest) {
    waste_method_report.push_back("Sink");
  }
  if (trash == largest) {
    waste_method_report.push_back("Trash");
  }
  if (feed_to_pet == largest) {
    waste_method_report.push_back("Feed to pet");
  }
  if (compost == largest) {
    waste_method_report.push_back("Compost");
  }
  if (donation == largest) {
    waste_method_report.push_back("Donation");
  }
  if (other == largest) {
    waste_method_report.push_back("Other");
  }
  common_mechanism_disposal_ = waste_method_report;
}

void FoodWastageReport::GenerateSuggestedStrats() {
  // No parameters required. Call GenerateCommonReason before using this
  // function. Each strategy does not need to be repeated if multiple conditions
  // are met.
  std::vector<std::string> generated_strats{};
  bool donate{false};
  bool buy_less{false};
  bool cook_smaller{false};
  bool recycle{true};
  for (std::string reason : common_reason_) {
    if (reason == "Expired") {
      recycle = false;
      donate = true;
    }
    if (reason == "Taste bad") {
      buy_less = true;
    }
    if (reason == "Too much left overs") {
      buy_less = true;
      cook_smaller = true;
    }
  }
  if (donate) {
    generated_strats.push_back("Donate before expiration");
  }
  if (buy_less) {
    generated_strats.push_back("Buy less food");
  }
  if (cook_smaller) {
    generated_strats.push_back("Cook smaller servings");
  }
  if (recycle) {
    generated_strats.push_back("Recycle before expiration");
  }
  if (common_reason_.empty()) {
    generated_strats.clear();
  }
  suggested_strats_ = generated_strats;
}