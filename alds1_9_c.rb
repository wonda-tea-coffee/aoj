def max_heapify(a, i)
  h = a.size

  l = i * 2
  r = i * 2 + 1

  if l < h && a[l] > a[i]
    largest = l
  else
    largest = i
  end

  if r < h && a[r] > a[largest]
    largest = r
  end

  if largest < h && largest != i
    a[i], a[largest] = a[largest], a[i]
    max_heapify(a, largest)
  end
end

def heap_extract_max(a)
  raise if a.size < 2

  max = a[1]
  a.delete_at(1)
  max_heapify(a, 1)
  max
end

def heap_increase_key(a, key)
  a << key
  i = a.size - 1
  while i > 1 && a[i / 2] < a[i]
    a[i], a[i / 2] = a[i / 2], a[i]
    i /= 2
  end
end

def insert(a, k)
  heap_increase_key(a, k)
end

a = [-1]
out = []
while true
  command, key = gets.chomp.split
  key = key.to_i

  case command
  when 'insert'
    heap_increase_key(a, key)
    # p a.drop(1)
  when 'extract'
    out << heap_extract_max(a)
    # p a.drop(1)
  else
    break
  end
end

out.each do |o|
  puts o
end