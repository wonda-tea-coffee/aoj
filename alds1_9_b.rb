def max_heapify(a, i)
  l = i * 2
  r = i * 2 + 1
  h = a.size

  if l < h && a[l] > a[i]
    largest = l
  else
    largest = i
  end

  if r < h && a[r] > a[largest]
    largest = r
  end

  if largest != i
    a[i], a[largest] = a[largest], a[i]
    max_heapify(a, largest)
  end
end

def build_max_heap(a)
  (a.size / 2).downto(1) do |i|
    max_heapify(a, i)
  end
end

gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)
a.unshift(-1)

build_max_heap(a)

puts a.drop(1).map{|ai| " #{ai.to_s}"}.join
