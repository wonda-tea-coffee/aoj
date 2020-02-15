def swap(a, i, j)
  tmp = a[i]
  a[i] = a[j]
  a[j] = tmp
end

def partition(a, p, r)
  ans = p
  p.upto(r - 1) do |i|
    if a[i] <= a[r]
      swap(a, ans, i)
      ans += 1
    end
  end
  swap(a, ans, r)
  ans
end

n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)

idx = partition(a, 0, a.size - 1)
ans = []
a.each.with_index do |ai, i|
  ans <<
    if i == idx
      "[" + ai.to_s + "]"
    else
      ai.to_s
    end
end
puts ans.join(' ')