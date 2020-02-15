@cnt = 0

def merge(a, left, mid, right)
  n1 = mid - left
  n2 = right - mid

  l = [] * n1
  r = [] * n2

  n1.times do |i|
    l[i] = a[left + i]
  end

  n2.times do |i|
    r[i] = a[mid + i]
  end

  l[n1] = 0xffffffff
  r[n2] = 0xffffffff
  i = 0
  j = 0
  left.upto(right - 1) do |k|
    @cnt += 1
    if l[i] <= r[j]
      a[k] = l[i]
      i = i + 1
    else
      a[k] = r[j]
      j = j + 1
    end
  end
end

def merge_sort(a, left, right, depth)
  # print '   ' * depth
  # puts "#{a}, left = #{left}, right = #{right}"
  if left + 1 < right
    mid = (left + right) / 2
    merge_sort(a, left, mid, depth + 1)
    merge_sort(a, mid, right, depth + 1)
    merge(a, left, mid, right)
  end
end

n = gets.chomp.to_i
s = gets.chomp.split.map(&:to_i)

merge_sort(s, 0, n, 0)

puts s.map(&:to_s).join(' ')
puts @cnt