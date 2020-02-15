class Card
  attr_reader :suit, :number

  def initialize(val)
    @suit = val[0]
    @number = val[1].to_i
  end

  def to_s
    "#{suit} #{number}"
  end

  def <=(card)
    number <= card.number
  end

  def ==(card)
    suit == card.suit && number == card.number
  end
end

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
  l << Card.new(["?", 0xffffffff.to_s])
  r << Card.new(["?", 0xffffffff.to_s])
  left.upto(right - 1) do |i|
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

def _quicksort(a, p, r)
  if p < r
    q = partition(a, p, r)
    _quicksort(a, p, q - 1)
    _quicksort(a, q + 1, r)
  end
  a
end

def quicksort(a)
  _quicksort(a, 0, a.size - 1)
end

def stable?(bef, aft)
  merge_sort(bef) == aft
end

n = gets.chomp.to_i
a = []

n.times do
  a << Card.new(gets.chomp.split)
end

sorted = quicksort(a.dup)

puts stable?(a, sorted) ? 'Stable' : 'Not stable'
puts sorted.map(&:to_s).join("\n")