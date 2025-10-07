#include "PmergeMe.hpp"
#include <utility> // std::pair.
#include <algorithm> // std::lower_bound, std::find_if.
#include <iterator> // std::advance, std::distance.
#include <optional>
#include <vector>
#include <deque>

namespace details
{
	// Pair type for (smaller, larger)
	using IntPair = std::pair<int, int>;
}

// Vector-specific implementation namespace
namespace vector_impl
{
	// Extracts remainder if odd size
	std::optional<int> extract_remainder(std::vector<int>& container)
	{
		if (container.size() % 2 != 0)
		{
			int remainder = container.back();
			container.pop_back();
			return remainder;
		}
		return std::nullopt;
	}

	// Createing pairs and separating into chains
	void create_and_separate_chains(const std::vector<int>& container, std::vector<int>& main_chain, std::vector<details::IntPair>& pendants)
	{
		auto it = container.begin();
		while (it != container.end())
		{
			int first = *it++;
			int second = *it++;
			auto [small, large] = first < second ? std::make_pair(first, second) : std::make_pair(second, first);
			main_chain.push_back(large);
			pendants.push_back({small, large});
		}
	}

	// Reordering pendants to match sorted main order
	std::vector<details::IntPair> reorder_pendants(const std::vector<int>& sorted_main, const std::vector<details::IntPair>& pendants)
	{
		std::vector<details::IntPair> ordered;
		for (int large : sorted_main) // for each element inside sorted_main copy it into large
		{
			auto it = std::find_if(pendants.begin(), pendants.end(), [large](const details::IntPair& p)
			{
				return p.second == large;
			});
			if (it != pendants.end())
			{
				ordered.push_back(*it);
			}
		}
		return ordered;
	}

	// Generates Jacobsthal sequence up to limit
	std::vector<size_t> generate_jacobsthal_sequence(size_t limit)
	{
		std::vector<size_t> sequence;
		size_t a = 1, b = 3;
		while (a < limit)
		{
			sequence.push_back(a);
			size_t next = b + 2 * a;
			a = b;
			b = next;
		}
		return sequence;
	}

	// Processing milestones into reverse batches
	void add_milestone_batches(std::vector<size_t>& batches, const std::vector<size_t>& sequence, size_t& last)
	{
		for (size_t milestone : sequence) // for each element in sequence copy it into milestone
		{
			for (size_t j = milestone; j > last; --j)
			{
				batches.push_back(j - 1);
			}
			last = milestone;
		}
	}

	// Adding final remainder batch if needed
	void add_remainder_batch(std::vector<size_t>& batches, size_t num_pendants, size_t last)
	{
		for (size_t j = num_pendants; j > last; --j)
		{
			batches.push_back(j - 1);
		}
	}

	// Inserting value via binary search in range
	void binary_insert(std::vector<int>& chain, int value, size_t range)
	{
		auto end = chain.begin();
		std::advance(end, range);
		auto pos = std::lower_bound(chain.begin(), end, value);
		chain.insert(pos, value);
	}

	// Core recursive Ford-Johnson sort
	void ford_johnson_sort(std::vector<int>& container)
	{
		if (container.size() < 2) return;
		auto remainder = extract_remainder(container);
		std::vector<int> main_chain;
		std::vector<details::IntPair> pendants;
		create_and_separate_chains(container, main_chain, pendants);
		ford_johnson_sort(main_chain);
		auto ordered_pendants = reorder_pendants(main_chain, pendants);
		if (!ordered_pendants.empty())
		{
			auto jacob_seq = generate_jacobsthal_sequence(ordered_pendants.size());
			std::vector<size_t> plan;
			size_t last = 0;
			add_milestone_batches(plan, jacob_seq, last);
			add_remainder_batch(plan, ordered_pendants.size(), last);
			for (size_t idx : plan)
			{
				const auto& pair = ordered_pendants[idx];
				int value = pair.first;
				int partner = pair.second;
				auto pos_it = std::find(main_chain.begin(), main_chain.end(), partner);
				size_t search_range = std::distance(main_chain.begin(), pos_it);
				binary_insert(main_chain, value, search_range);
			}
		}
		if (remainder.has_value())
		{
			binary_insert(main_chain, remainder.value(), main_chain.size());
		}
		container = std::move(main_chain);
	}
}

// Deque-specific implementation
namespace deque_impl
{
	std::optional<int> extract_remainder(std::deque<int>& container)
	{
		if (container.size() % 2 != 0)
		{
			int remainder = container.back();
			container.pop_back();
			return remainder;
		}
		return std::nullopt;
	}

	void create_and_separate_chains(const std::deque<int>& container, std::deque<int>& main_chain, std::vector<details::IntPair>& pendants)
	{
		auto it = container.begin();
		while (it != container.end())
		{
			int first = *it++;
			int second = *it++;
			auto [small, large] = first < second ? std::make_pair(first, second) : std::make_pair(second, first);
			main_chain.push_back(large);
			pendants.push_back({small, large});
		}
	}

	std::vector<details::IntPair> reorder_pendants(const std::deque<int>& sorted_main, const std::vector<details::IntPair>& pendants)
	{
		std::vector<details::IntPair> ordered;
		for (int large : sorted_main)
		{
			auto it = std::find_if(pendants.begin(), pendants.end(), [large](const details::IntPair& p)
			{
				return p.second == large;
			});
			if (it != pendants.end())
			{
				ordered.push_back(*it);
			}
		}
		return ordered;
	}

	std::vector<size_t> generate_jacobsthal_sequence(size_t limit)
	{
		std::vector<size_t> sequence;
		size_t a = 1, b = 3;
		while (a < limit)
		{
			sequence.push_back(a);
			size_t next = b + 2 * a;
			a = b;
			b = next;
		}
		return sequence;
	}

	void add_milestone_batches(std::vector<size_t>& batches, const std::vector<size_t>& sequence, size_t& last)
	{
		for (size_t milestone : sequence)
		{
			for (size_t j = milestone; j > last; --j)
			{
				batches.push_back(j - 1);
			}
			last = milestone;
		}
	}

	void add_remainder_batch(std::vector<size_t>& batches, size_t num_pendants, size_t last)
	{
		for (size_t j = num_pendants; j > last; --j)
		{
			batches.push_back(j - 1);
		}
	}

	void binary_insert(std::deque<int>& chain, int value, size_t range)
	{
		auto end = chain.begin();
		std::advance(end, range);
		auto pos = std::lower_bound(chain.begin(), end, value);
		chain.insert(pos, value);
	}

	void ford_johnson_sort(std::deque<int>& container)
	{
		if (container.size() < 2) return;
		auto remainder = extract_remainder(container);
		std::deque<int> main_chain;
		std::vector<details::IntPair> pendants;
		create_and_separate_chains(container, main_chain, pendants);
		ford_johnson_sort(main_chain);
		auto ordered_pendants = reorder_pendants(main_chain, pendants);
		if (!ordered_pendants.empty())
		{
			auto jacob_seq = generate_jacobsthal_sequence(ordered_pendants.size());
			std::vector<size_t> plan;
			size_t last = 0;
			add_milestone_batches(plan, jacob_seq, last);
			add_remainder_batch(plan, ordered_pendants.size(), last);
			for (size_t idx : plan)
			{
				const auto& pair = ordered_pendants[idx];
				int value = pair.first;
				int partner = pair.second;
				auto pos_it = std::find(main_chain.begin(), main_chain.end(), partner);
				size_t search_range = std::distance(main_chain.begin(), pos_it);
				binary_insert(main_chain, value, search_range);
			}
		}
		if (remainder.has_value())
		{
			binary_insert(main_chain, remainder.value(), main_chain.size());
		}
		container = std::move(main_chain);
	}
}

void PmergeMe::sort(std::vector<int>& container)
{
	vector_impl::ford_johnson_sort(container);
}

void PmergeMe::sort(std::deque<int>& container)
{
	deque_impl::ford_johnson_sort(container);
}