import heapq

def main():
    t = int(input())
    for _ in range(t):
        [_, k, x] = map(int, input().strip().split())
        nums = list(set(map(int, input().strip().split())))

        nums.sort()
        gaps = [] # (dist_to_neighbor, point, direction)
        seen = set()

        # add 0 as an option if it isn't in the array
        if nums[0] != 0:
            gaps.append((-nums[0], 0, 1))
            seen.add(0)
        
        # add x as an option as a last resort
        gaps.append((-(x - nums[-1]), x, -1))
        seen.add(x)

        for i in range(len(nums) - 1):
            gap = nums[i + 1] - nums[i]
            mid = gap // 2
            if gap % 2 == 0:
                if (nums[i] + mid - 1) not in seen:
                    gaps.append((-(mid - 1), nums[i] + mid - 1, -1))
                    seen.add(nums[i] + mid - 1)
                if nums[i] + mid not in seen:
                    gaps.append((-mid, nums[i] + mid, 1))
                    seen.add(nums[i] + mid)
            else:
                if nums[i] + mid not in seen:
                    gaps.append((-mid, nums[i] + mid, -1))
                    seen.add(nums[i] + mid)
                if gap > 1 and nums[i] + mid + 1 not in seen:
                    gaps.append((-(gap - mid - 1), nums[i] + mid + 1, 1))
                    seen.add(nums[i] + mid + 1)


        heapq.heapify(gaps)

        res = []
        for _ in range(k):
            [dist, point, direction] = heapq.heappop(gaps)

            res.append(point)

            if dist < 0 and point + direction not in seen:
                heapq.heappush(gaps, (dist + 1, point + direction, direction))
                seen.add(point + direction)
        res.sort()
        print(' '.join(map(str, res)))


if __name__ == "__main__":
    main()
