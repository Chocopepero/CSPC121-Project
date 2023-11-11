#ifndef FOOD_WASTAGE_TRACKER_H_
#define FOOD_WASTAGE_TRACKER_H_

// Samuel Kim
// CPSC 121L - 02
// 2023-11-09
// samkunkim@csu.fullerton.edu
// @ChocoPepero

#include <iostream>
#include <vector>

#include "food_wastage_report.h"

class FoodWastageTracker {
 public:
  bool AddFoodWasteRecord(const FoodWastageRecord& record_to_add) {
    waste_record_.push_back(record_to_add);
    for (std::vector<FoodWastageRecord>::iterator record_to_add_iterator =
             waste_record_.begin();
         record_to_add_iterator != waste_record_.end();
         record_to_add_iterator++) {
      if (&record_to_add == &*record_to_add_iterator) {
        return true;
      }
    }
    return false;
  }
  bool DeleteFoodWasteRecord(FoodWastageRecord record_to_remove) {
    FoodWastageRecord* record_to_remove_ptr{};
    for (std::vector<FoodWastageRecord>::iterator record_to_remove_iterator =
             waste_record_.begin();
         record_to_remove_iterator != waste_record_.end();
         record_to_remove_iterator++) {
      if (record_to_remove_ptr == &(*record_to_remove_iterator))
        waste_record_.erase(record_to_remove_iterator);
      if (record_to_remove_ptr != &*record_to_remove_iterator) {
        return true;
      }
    }
    return false;
  }
  std::vector<FoodWastageRecord> GetWasteRecord() const {
    return waste_record_;
  }
  void GenerateReport() {
    waste_report_.GenerateCommonWasteFood(waste_record_);
    waste_report_.GenerateCommonWasteMeals(waste_record_);
    waste_report_.CalculateCost(waste_record_);
    waste_report_.GenerateCommonReason(waste_record_);
    waste_report_.GenerateCommonMechOfDisposal(waste_record_);
    waste_report_.GenerateSuggestedStrats();
  }
  FoodWastageReport GetWasteReport() const { return waste_report_; }

 private:
  std::vector<FoodWastageRecord> waste_record_;
  FoodWastageReport waste_report_;
};

#endif