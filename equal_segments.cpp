// Заданы n точек на координатной прямой. Вам требуется покрыть все точки на прямой k отрезками одинаковой длины.
// Необходимо определить, какую минимальную длину могут иметь отрезки.

#include <iostream>
#include <ranges>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> points(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n,  points.begin());
    std::set<int> poits_set(points.begin(), points.end());
    std::vector<int> uniq_points(poits_set.begin(), poits_set.end());
    for(auto v: uniq_points) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    auto range_start = uniq_points.front();
    auto range_width = uniq_points.back() - range_start;
    auto seg_len_estimation = static_cast<int>(std::ceil(static_cast<double>(range_width) / k));
    std::list<std::vector<std::pair<size_t, size_t>>> candidates, success_cover;
    for (size_t i{0}; i < uniq_points.size(); i++) {
        if (uniq_points[i] - range_start > seg_len_estimation) {
            break;
        }
        candidates.push_back({std::make_pair(0ul, i)});
    }
    while (!candidates.empty()) {
        auto& candidate = candidates.front();
        size_t last_point_idx = candidate.back().second;
        bool allPointsProcessed = last_point_idx == uniq_points.size() - 1;
        if (candidate.size() == k) {
            // Все отрезки размещены
            if (allPointsProcessed) {
                // последний отрезок содержит последний элемент последовательности - успех
                success_cover.splice(success_cover.end(), candidates, candidates.begin());
            } else {
                // Но не все точки покрыты отрезками - выбрасываем кандидата
                candidates.pop_front();
            }
        } else {
            if (!allPointsProcessed) {
                // Добавляем кандидатов с еще одим отрезком
                auto seg_start_idx = last_point_idx + 1;
                for (size_t i{seg_start_idx}; i < uniq_points.size(); i++) {
                    if (uniq_points[i] - uniq_points[seg_start_idx] > seg_len_estimation) {
                        break; 
                    }
                    auto new_candidate = candidate;
                    new_candidate.push_back(std::make_pair(seg_start_idx, i));
                    candidates.push_back(std::move(new_candidate));
                }
                candidates.pop_front();
            } else {
                // Дошли до последней точки, но не использовали все отрезки - тоже успех 
                // (случай, когда отрезков больше чем уникальных точек)
                success_cover.splice(success_cover.end(), candidates, candidates.begin());
            }
        }
    }

    // Нарисуем всех успешных кандидатов для отладки
    std::vector<int> max_segm_widths;  
    for (auto& segments: success_cover) {
        int max_segm_width{0};
        for(auto [first, last]: segments) {
            auto width = uniq_points[last] - uniq_points[first];
            if (width > max_segm_width) {
                max_segm_width = width;
            } 
            // std::cout << "(" << uniq_points[first] << "..." << uniq_points[last] << ") ";
        }
        max_segm_widths.push_back(max_segm_width);
        // std::cout << std::endl;
    }

    std::cout << std::ranges::min(max_segm_widths) << std::endl;

}