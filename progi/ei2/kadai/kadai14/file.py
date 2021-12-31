def reverse_linked_list_inplace(self):
    current_node = self.head
    previous_node = None
    while current_node:
        # ポインタを逆にする前に次のノードを保持
        next_node = current_node.next_node
        # 現在のノードの次のノードを前のノードに変更
        current_node.next_node = previous_node
        # ノードを一つ進める
        previous_node = current_node
        current_node = next_node
        # 一番最後に head を変更
        self.head = previous_node
