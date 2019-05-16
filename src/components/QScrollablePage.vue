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
  /* width */
  ::-webkit-scrollbar {
    width: 8px;
  }

  /* Track */
  ::-webkit-scrollbar-track {
    background: #f1f1f1; 
  }
  
  /* Handle */
  ::-webkit-scrollbar-thumb {
    background: rgb(180, 180, 180); 
  }

  /* Handle on hover */
  ::-webkit-scrollbar-thumb:hover {
    background: rgb(160, 160, 160); 
  }
</style>
