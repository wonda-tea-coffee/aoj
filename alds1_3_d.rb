s = gets.chomp.chars
pools = []
h = 0
cnt = 0
s.each.with_index do |si, i|
  if si == '_'
    cnt += 1
    next
  end

  if si == '/'
    h += 1
  elsif si == '\\'
    h -= 1
  end

  if h == 0
    cnt + 1
  end
end

puts pools.inject(&:+)
puts "#{pools.size} #{pools.map(&:to_s).join(' ')}"
