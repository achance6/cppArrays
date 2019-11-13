template<typename T>
SparseArray<T>::SparseArray(int length, T def) {
    head = nullptr;
	len = length;
	this->def = def;
}

template<typename T>
typename T SparseArray<T>::get(int position) {
	//Invalid position
	if (position < 0 || position > len) {
		std::cerr << "INVALID POSITION";
		std::exit(0);
	}
	Node* node = find(position);
	//Position doesn't exist in list
	if (node == NULL) {
		return def;
	}
	//Positon exists
	else {
		return node->data;
	}
}
template<typename T>
void SparseArray<T>::put(int position, T data) {
	//Invalid position
	if (position < 0 || position > len) {
		std::cerr << "INVALID POSITION";
		std::exit(0);
	}
	//Node at position exists
	Node* node = find(position);
	if (node != NULL && data != def) {
		node->data = data;
	}
	//Node at position doesn't exist -> prepend to head
	else if (node == NULL) {
		prepend(position, data);
	}
}

template<typename T>
typename SparseArray<T>::Node* SparseArray<T>::find(int position) {
	Node* cur = head;
	while (cur != NULL && cur->position != position) {
		cur = cur->next;
	}
	return cur;
}

template<typename T>
void SparseArray<T>::prepend(int position, T data) {
	Node* node = new Node();
	node->data = data;
	node->next = head;
	node->position = position;
	head = node;
}


