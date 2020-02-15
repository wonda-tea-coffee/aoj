def bsearch(a, n)
  min = 0
  max = a.size - 1
  while true
    mid = (max + min) / 2

    if a[mid] < n
      break if mid + 1 == min
      min = mid + 1
    elsif a[mid] > n
      break if mid - 1 == max
      max = mid - 1
    else
      return true
    end
  end
  false
end

N = gets.chomp.to_i
S = gets.chomp.split.map(&:to_i)
Q = gets.chomp.to_i
T = gets.chomp.split.map(&:to_i)

ans = 0
T.each do |ti|
  ans += 1 if bsearch(S, ti)
end
puts ans