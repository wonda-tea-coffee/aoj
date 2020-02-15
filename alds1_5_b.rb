def merge(a, left, mid, right)
  n1 = mid - left
  n2 = right - mid
  l = [] * n1
  r = [] * n2
  n1.times do |i|
    l << a[left + i]
  end
  n2.times do |i|
    r << a[mid + i]
  end
  li = 0
  ri = 0
  l << 0xffffffff
  r << 0xffffffff
  left.upto(right - 1) do |i|
    @cnt += 1
    if l[li] <= r[ri]
      a[i] = l[li]
      li += 1
    else
      a[i] = r[ri]
      ri += 1
    end
  end
end

def _merge_sort(a, left, right)
  if left + 1 < right
    mid = (left + right) / 2
    _merge_sort(a, left, mid)
    _merge_sort(a, mid, right)
    merge(a, left, mid, right)
  end
  a
end

def merge_sort(a)
  _merge_sort(a, 0, a.size)
end

n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)

@cnt = 0
puts merge_sort(a).map(&:to_s).join(' ')
puts @cnt