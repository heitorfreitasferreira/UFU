mat_dist = rbind(c(0, 9, 3, 6, 11), c(9, 0, 7, 5, 10), c(3, 7, 0, 9, 2), c(6, 5, 9, 0, 8), c(11, 10, 2, 8, 0))

mat_dist = as.dist(mat_dist)

cluster = hclust(mat_dist, method = "complete")
plot(cluster)