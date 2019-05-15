<template>
  <q-page v-bind:id="pageId" style="overflow:auto;">
    <slot></slot>
  </q-page>
</template>

<script>
export default {
  name: "QScrollablePage",
  data () {
    return {}
  },
  props: {
    pageId: {
      type: String,
      default: "",
      required: true
    },
    mainHeaderId: {
      type: String,
      default: "",
      required: true
    }
  },
  computed: {},
  methods: {},
  mounted () {
    var header = document.getElementById(this.mainHeaderId)
    var page = document.getElementById(this.pageId)
    page.style.height= `${window.innerHeight-header.offsetHeight}px`

    window.onresize = () => {
      page.style.height= `${window.innerHeight-header.offsetHeight}px`
    }
  }
}
</script>

<style>
</style>
